// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : blitters.c
// *
// * note : A bunch of fast MMX blitters of various kinds
// *        Alpha blending, additive blending, you name it
// *        Many non-ASM substitutes needs writing if we're gonna
// *        support GNU C
// *
// ******************************************************************


#include "xgfx2d/blitters.h"


DECLARE_BLITTER(normal_blit,none) {
	if (len==0) return;
	memcpy(d,s,len*4);
}

DECLARE_BLITTER(sprite_blit,none) {
	for (; len; len--, s++, d++)
		if ((*s & 0xffffff) != 0) *d=*s;
}

//use for fonts and stuff
//this can probably be optimized
DECLARE_BLITTER(colorize_sprite_blit,color) {
#ifndef __GNUC__
	if (len==0)
		return;
	__asm {
		pushad
		mov esi,s
		mov edi,d
		mov ecx,len
		mov ebx,color
sprite_loop:
		mov eax,[esi]
		and eax,0xffffff
		jz skip_pixel          //change to conditional move?
		mov [edi],ebx
skip_pixel:
		add edi,4
		add esi,4
		dec ecx
		jnz sprite_loop
		popad
	} 
#endif
}

//Curly's Alpha Blit
//2 pixels at a time to get pairing.. not sure if it helps
DECLARE_BLITTER(alphavalue_blit,alpha) {
#ifndef __GNUC__
	__asm {
		mov esi,s
		mov edi,d
		mov ecx,len
		shr ecx,1 
		movd mm7, [alpha] // alpha = 0 - 255
		punpcklbw mm7, mm7
		punpcklwd mm7, mm7
		punpcklwd mm7, mm7
		psrlw mm7, 4
		
		//esi -> source
		//edi -> dest
alphaloop:
		
		movd mm0, [esi]
		movd mm2, [esi+4]
		punpcklbw mm0, mm0
		movd mm1, [edi]
		punpcklbw mm2, mm2
		movd mm3, [edi+4]
		punpcklbw mm1, mm1
		punpcklbw mm3, mm3
		
		// öka upp datan till wordstorlek
		psrlw mm0, 4
		psrlw mm1, 4
		psrlw mm2, 4
		psrlw mm3, 4
		
		//vikta
		psubw mm1, mm0
		pmulhw mm1, mm7
		psrlw mm0, 4
		paddw mm0, mm1
		
		psubw mm3, mm2
		pmulhw mm3, mm7
		psrlw mm2, 4
		paddw mm2, mm3
		
		packuswb mm0, mm0
		packuswb mm2, mm2
		
		movd [edi], mm0
		add esi,8
		movd [edi+4], mm2
		add edi,8
		dec ecx
		jnz alphaloop
		emms
	}
#endif
}

DECLARE_BLITTER(alphavalue_sprite_blit,alpha) {
#ifndef __GNUC__
	__asm {
		mov esi,s
		mov edi,d
		mov ecx,len
		movd mm7, [alpha] // alpha = 0 - 255
		punpcklbw mm7, mm7
		punpcklwd mm7, mm7
		punpcklwd mm7, mm7
		psrlw mm7, 4
			
		//esi -> source
		//edi -> dest
alphaloop:
		mov eax,[esi]
		movd mm0, [esi]
		and eax,0xffffff
		jz skipthispixel

		//unpack to words and apply shift bias
		punpcklbw mm0, mm0
		movd mm1, [edi]
		punpcklbw mm1, mm1
		psrlw mm0, 4
		psrlw mm1, 4
		
		//weighting
		psubw mm1, mm0
		pmulhw mm1, mm7
		psrlw mm0, 4
		paddw mm0, mm1
		
		packuswb mm0, mm0
		
		movd [edi], mm0
skipthispixel:
		add esi,4
		add edi,4
		dec ecx
		jnz alphaloop
		emms
	}
#endif
}


DECLARE_BLITTER(alphavalue50_blit,none) {
#ifndef __GNUC__
	__asm {
		mov esi,s
		mov edi,d
		mov ecx,len
alpha50_loop:
		mov eax,[esi]
		mov ebx,[edi]
		shr eax,1
		shr ebx,1
		and eax,0x7F7F7F7F
		and ebx,0x7F7F7F7F
		add eax,ebx
		mov [edi],eax
		add edi,4
		add esi,4
		dec ecx
		jnz alpha50_loop
	}
#endif
}


DECLARE_BLITTER(additive_blit,none) {
#ifndef __GNUC__
	//process 2 pixels at a time 
	if (len>3) {
		__asm {
			mov esi,s
			mov edi,d
			mov ebx,len
			mov ecx,len
			mov edx,ecx
			shr ecx,1
			and ebx,3
			mov len,ebx
addblitloop:
			movq mm0,[esi]
			movq mm1,[edi]
			paddusb mm0,mm1
			movq [edi],mm0
			add esi,8
			add edi,8
			sub edx,2
			dec ecx
			jnz addblitloop
			
			cmp edx,0
			jz skipfinishadd
			movd mm0,[esi]
			movd mm1,[edi]
			paddusb mm0,mm1
			movd [edi],mm0
skipfinishadd:
			emms
		}
	}
	
#else
	for (; len; len--, d++, s++) {
		int b=(*d & 0xff) + (*s & 0xff);
		int g=(*d & 0xff00) + (*s & 0xff00); 
		int r=(*d & 0xff0000) + (*s & 0xff0000);
		if (b>255) b=255; if (g>0xff00) g=0xff00; if (r>0xff0000) r=0xff0000;
		*d=r | g | b;
	}
#endif
}

DECLARE_BLITTER(subtractive_blit,none) {
#ifndef __GNUC__
	__asm {
		mov esi,s
		mov edi,d
		mov ecx,len
		shr ecx,1
sub_loop:
		movq mm1,[esi]
		movq mm0,[edi]
		psubusb mm0,mm1
		movq [edi],mm0
		
		add esi,8
		add edi,8
		dec ecx
		jnz sub_loop
		emms
	}
#endif
};


//to be optimized..
DECLARE_BLITTER(additive_alpha_blit,alpha) {
	//alpha=255-alpha;
#ifndef __GNUC__
	__asm {
		mov esi,s
		mov edi,d
			//mov edx,alpha
alphaloop2:
		mov eax, [esi]
		
		mov ebx, eax
		and eax, 0x00ff00ff
		imul alpha
		shr eax, 8
		and eax, 0x00ff00ff
		mov ecx, eax
		
		mov eax,ebx
		and eax,0x0000ff00
		imul alpha
		shr eax, 8
		and eax,0x0000ff00
		
		add eax,ecx
		
		movd mm0,eax
		movd mm1,[edi]
		paddusb mm0,mm1
		movd [edi], mm0
		add esi,4
		add edi,4
		dec len
		jnz alphaloop2
		emms
	}  
	
#else
	
	if (alpha>255) alpha=255;
	if (alpha<=0) return;
	for (; len; len--, d++, s++) {
		int b=(*d & 0xff) + ((*s & 0xff)*alpha>>8);
		int g=(*d & 0xff00) + (((*s & 0xff00)*alpha>>8)&0xff00); 
		int r=(*d & 0xff0000) + (((*s & 0xff0000)*alpha>>8)&0xff0000);
		if (b>255) b=255; if (g>0xff00) g=0xff00; if (r>0xff0000) r=0xff0000;
		*d=r | g | b;
	}
#endif
}

DECLARE_BLITTER(multiply_blit,none) {
	
#ifndef __GNUC__
	__asm {
		mov esi,s
		mov edi,d
		mov ecx,len
mulblitloop:
		movd mm0, [esi]
		movd mm1, [edi]
		punpcklbw mm0, mm0
		psrlw mm0, 4
		punpcklbw mm1, mm1
		psrlw mm1, 4
		
		pmulhw mm0, mm1
		packuswb mm0, mm0
		
		movd [edi],mm0
		
		add esi,4
		add edi,4
		dec ecx
		jnz mulblitloop
		emms
	}
#else
	for (; len; len--) {
		int b = ((*s & 0xff) * (*d & 0xff)) >> 8;
		int g = (((*s & 0xff00) * (*d & 0xff00)) >> 16) & 0xff00;
		int r = (((*s & 0xff0000) * ((*d & 0xff0000) >> 16)) >> 8) & 0xff0000;
		
		*d = b | g | r;
		s++;
		d++;
	}
#endif
}

//to be optimized...
DECLARE_BLITTER(invert_blit,none) {
	for (; len; len--) {
		int r1=255-((*s&0xff0000)>>16);
		int g1=255-((*s&0xff00)>>8);
		int b1=255-(*s&0xff);
		int r2=(*d&0xff0000)>>16;
		int g2=(*d&0xff00)>>8;
		int b2=*d&0xff;
		
		int r3=(r1*r2+(255-r1)*(255-r2))>>8;
		//r3=(r1*r2+65025-255*r2-255*r1+r1*r2);
		
		int g3=(g1*g2+(255-g1)*(255-g2))>>8;
		int b3=(b1*b2+(255-b1)*(255-b2))>>8;
		
		*d=(r3<<16) | (g3<<8) | b3;
		s++;
		d++;
	}
}
