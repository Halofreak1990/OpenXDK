// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : drawprim.c
// *
// * note : A bunch of drawing primitives
// *
// ******************************************************************
#include <math.h>
#include "xgfx2d/drawprim.h"

void clear(Bitmap *bmp, uint32 col) {
	int y;
	if (col==0)
	{
		for (y=0; y<bmp->h; y++)
		{
			uint32 *p = bmp->data + bmp->pitch * y;
			memset(p,0x0,bmp->w*4);
		}
	}
	else 
		for (y=0; y<bmp->h; y++) 
			hline(bmp,0,y,bmp->w,col);
}

//SLOW of course
void putpixel(Bitmap *bmp, int x, int y, uint32 col)
{
	if (x<0 || y<0 || x>=bmp->w || y>=bmp->h)
		return;
	*(bmp->data + bmp->pitch*y + x) = col;
}

void line(Bitmap *bmp, int x1, int y1, int x2, int y2, int d) {
  int dx = x2-x1;
  int dy = y2-y1;
  int i1, i2;
  int x, y;
  int dd;

  /* worker macro */
  #define DO_LINE(pri_sign, pri_c, pri_cond, sec_sign, sec_c, sec_cond)    \
  {                                                                        \
    if (d##pri_c == 0) {                                                   \
      putpixel(bmp, x1, y1, d);                                                \
      return;                                                              \
    }                                                                      \
									                                                         \
    i1 = 2 * d##sec_c;                                                     \
    dd = i1 - (sec_sign (pri_sign d##pri_c));                              \
    i2 = dd - (sec_sign (pri_sign d##pri_c));                              \
									                                                         \
    x = x1;                                                                \
    y = y1;                                                                \
									                                                         \
    while (pri_c pri_cond pri_c##2) {                                      \
      putpixel(bmp, x, y, d);                                              \
									                                                         \
      if (dd sec_cond 0) {                                                 \
	      sec_c sec_sign##= 1;                                               \
	      dd += i2;                                                          \
      }                                                                    \
      else                                                                 \
	      dd += i1;                                                          \
									                                                         \
      pri_c pri_sign##= 1;                                                 \
    }                                                                      \
  }

  if (dx >= 0) {
    if (dy >= 0) {
      if (dx >= dy) {
	      /* (x1 <= x2) && (y1 <= y2) && (dx >= dy) */
	      DO_LINE(+, x, <=, +, y, >=);
      }
      else {
	      /* (x1 <= x2) && (y1 <= y2) && (dx < dy) */
	      DO_LINE(+, y, <=, +, x, >=);
      }
    }
    else {
      if (dx >= -dy) {
	      /* (x1 <= x2) && (y1 > y2) && (dx >= dy) */
	      DO_LINE(+, x, <=, -, y, <=);
      }
      else {
	      /* (x1 <= x2) && (y1 > y2) && (dx < dy) */
	      DO_LINE(-, y, >=, +, x, >=);
      }
    }
  }
  else {
    if (dy >= 0) {
      if (-dx >= dy) {
	      /* (x1 > x2) && (y1 <= y2) && (dx >= dy) */
	      DO_LINE(-, x, >=, +, y, >=);
      }
      else {
	      /* (x1 > x2) && (y1 <= y2) && (dx < dy) */
	      DO_LINE(+, y, <=, -, x, <=);
      }
    }
    else {
      if (-dx >= -dy) {
	      /* (x1 > x2) && (y1 > y2) && (dx >= dy) */
	      DO_LINE(-, x, >=, -, y, <=);
      }
      else {
	      /* (x1 > x2) && (y1 > y2) && (dx < dy) */
	      DO_LINE(-, y, >=, -, x, <=);
      }
    }
  }
}

void hline(Bitmap *bmp, int x1, int y, int x2, uint32 color) {
	uint32 *p;
	//Clipping and stuff
	if (y<0 || y>=bmp->h) return;
	if (x1==x2) return;
	if (x1>x2) return;
	if (x1<0) x1=0;
	if (x2>=bmp->w) x2=bmp->w;
	if (x2<0) return;
	if (x1>=bmp->w) return;
	//Draw the damn line!
	p=bmp->data+bmp->pitch*y+x1;
	__asm {
		mov ecx,x2
		sub ecx,x1
		mov edi,p
		mov eax,color
		rep stosd
	}
	
}

void vline(Bitmap *bmp,int x, int y1, int y2, uint32 color) {
	uint32 *p;
	int ptch;
	//Clipping and stuff
	if (x<0 || x>=bmp->w) return;
	if (y1==y2) return;
	if (y1>y2) return;
	if (y1<0) y1=0;
	if (y2>=bmp->h) y2=bmp->h;
	if (y2<0) return;
	if (y1>=bmp->h) return;
	//Draw the damn line!
	p=bmp->data+bmp->pitch*y1+x;
	ptch=bmp->pitch << 2;
	__asm {
		mov ecx,y2
		sub ecx,y1
		mov edi,p
		mov ebx,ptch
		mov eax,color
vlineloop:
		mov [edi],eax
		add edi,ebx
		dec ecx
		jnz vlineloop
	}
}

void rect(Bitmap *bmp,int x1, int y1, int x2, int y2, uint32 color) {
	hline(bmp, x1,y1,x2,color);
	hline(bmp, x1,y2,x2,color);
	vline(bmp, x1,y1,y2,color);
	vline(bmp, x2,y1,y2+1,color);
}

void rectfill(Bitmap *bmp,int x1, int y1, int x2, int y2, uint32 color) {
	int y;
	if (x1>x2) {int tmp=x1; x1=x2; x2=tmp;}
	if (y1>y2) {int tmp=y1; y1=y2; y2=tmp;}
	if (x2<0 || x1>=bmp->w) return;
	if (y2<0 || y1>=bmp->h) return;
	if (x1<0) x1=0;
	if (y1<0) y1=0;
	if (x2>=bmp->w) x2=bmp->w;
	if (y2>=bmp->h) y2=bmp->h;
	for (y=y1; y<y2; y++) 
		hline(bmp, x1,y,x2,color);
}




//Could somebody explain to me why this code works?? :-)
void circle(Bitmap *bmp,int x, int y, int radius, uint32 color) {
	int cx = 0;
	int cy = radius;
	int df = 1 - radius; 
	int d_e = 3;
	int d_se = -2 * radius + 5;
	int d=color;
	
	do {
		putpixel(bmp, x+cx, y+cy, d); 
		if (cx) 
			putpixel(bmp, x-cx, y+cy, d); 
		
		if (cy) 
			putpixel(bmp, x+cx, y-cy, d); 
		
		if ((cx) && (cy)) 
			putpixel(bmp, x-cx, y-cy, d); 
		
		if (cx != cy) {
			putpixel(bmp, x+cy, y+cx, d); 
			
			if (cx) 
				putpixel(bmp, x+cy, y-cx, d); 
			
			if (cy) 
				putpixel(bmp, x-cy, y+cx, d); 
			
			if (cx && cy) 
				putpixel(bmp, x-cy, y-cx, d); 
		}
		
		if (df < 0)  {
			df += d_e;
			d_e += 2;
			d_se += 2;
		}
		else { 
			df += d_se;
			d_e += 2;
			d_se += 4;
			cy--;
		} 
		cx++; 
	} while (cx <= cy);
}




void _alpha_pixel(Bitmap *bmp, int x, int y, uint32 sc, int alpha) {
	uint32 *p=bmp->data + bmp->pitch *y + x;
	alpha=255-alpha;
  __asm {
    movd mm7, alpha // alpha = 0 - 255
    punpcklbw mm7, mm7
    punpcklwd mm7, mm7
    punpcklwd mm7, mm7
    psrlw mm7, 4

    mov edi, p
    movd mm0, sc
    punpcklbw mm0, mm0
    movd mm1, [edi]
    punpcklbw mm1, mm1

    psrlw mm0, 4
    psrlw mm1, 4

    //vikta
    psubw mm1, mm0
    pmulhw mm1, mm7
    psrlw mm0, 4
    paddw mm0, mm1

    //packa ihop
    packuswb mm0, mm0
    movd [edi],mm0
    emms
  }
}

void alpha_pixel(Bitmap *bmp, int x, int y, uint32 sc, int alpha) {
	if (alpha<=0) 
		return;
	if (alpha>=255)
	{
		putpixel(bmp,x,y,sc); 
		return;
	}
	if (x<0 || y<0 || x>=bmp->w || y>=bmp->h) 
		return;
	_alpha_pixel(bmp, x,y,sc,alpha);
}	

#define ftofix(x) (int)(x*65536.0f)
#define itofix(x) (x<<16)
#define fixtoi(x) (x>>16)
#define trunc(i) ((i)&0xffff0000)
#define frac(i) ((i)&0x0000ffff)
#define invfrac(i) (0x0000ffff-((i)&0x0000ffff))

//use this for smooth scrolling starfields and stuff :)
//x and y are in 16.16 fixed point
void aa_pixel(Bitmap *bmp, int x, int y, int color)
{
	int xfrac=(x>>8)&0xff;
	int yfrac=(y>>8)&0xff;
	int invxfrac=0xff-xfrac;
	int invyfrac=0xff-yfrac;
	x>>=16; y>>=16;
	alpha_pixel(bmp,x,y,color,(invxfrac*invyfrac>>8));
	alpha_pixel(bmp,x+1,y,color,(xfrac*invyfrac>>8));
	alpha_pixel(bmp,x,y+1,color,(invxfrac*yfrac>>8));
	alpha_pixel(bmp,x+1,y+1,color,(xfrac*yfrac>>8));
}

void aa_pixel_float(Bitmap *bmp, float x, float y,int color) 
{
  aa_pixel(bmp,ftofix(x),ftofix(y),color);
}

#define UGLYFLOATSWAP(a,b) {float temp=a; a=b; b=temp;}

void aa_hslope(Bitmap *bmp, float x1, float y1, float x2, float y2, int32 color, int _alpha) 
{
	int x,y,slope;
	int xend,yend,xgap,yf;
	int alpha;
	int lclip=0;
	int fx1 = ftofix(x1), fy1 = ftofix(y1), 
		fx2 = ftofix(x2), fy2 = ftofix(y2);
	int iy1 = (int)(y1),iy2 = (int)(y2),
		ix1 = (int)(x1),ix2 = (int)(x2);

	float fslope;
	if (x2==x1) 
		return;
	if ((y1<0 && y2<0) || (y1>=bmp->h && y2>=bmp->h)) 
		return;
	if ((x1<0 && x2<0) || (x1>=bmp->w && x2>=bmp->w)) 
		return;
	if (x2<x1) 
	{
		UGLYFLOATSWAP(x1,x2); 
		UGLYFLOATSWAP(y2,y1); 
	}
 
	fslope=((y2-y1)/(x2-x1));
	slope=ftofix(fslope);
	
	//don't know why this row is here.. it probably should be commented out as it is =)
	//if (x1<0) {y1+=-x1*fslope; x1=0; lclip=1;}
	
	//Do first endpoint
	xend = trunc(fx1+0x8000);
	yend = fy1 + (slope*(xend-fx1)>>16);

	xgap = invfrac(fx1+0x8000);
	ix1=fixtoi(xend);
	iy1=fixtoi(yend);
	//if (!lclip) {
		alpha_pixel(bmp,ix1,iy1,color,(invfrac(yend)>>8)*(xgap>>8)*_alpha>>16);
		alpha_pixel(bmp,ix1,iy1+1,color,(frac(yend)>>8)*(xgap>>8)*_alpha>>16);
	//}
	yf=yend+slope;
	//Do second endpoint
	xend = trunc(fx2+0x8000);
	yend = fy2 + (slope*(xend-fx2)>>16);

	xgap = frac(fx2-0x8000);
	ix2=fixtoi(xend);
	iy2=fixtoi(yend);
	
	alpha_pixel(bmp,ix2,iy2,color,(invfrac(yend)>>8)*(xgap>>8)*_alpha>>16);
	alpha_pixel(bmp,ix2,iy2+1,color,(frac(yend)>>8)*(xgap>>8)*_alpha>>16);
	if (ix2>bmp->w) 
		ix2=bmp->w;

  
	for (x=ix1+1; x<ix2; x++) 
	{
		int a;
		alpha=(yf&0xffff)>>8;
		y=yf>>16;
		a=(_alpha!=255) ? alpha*_alpha>>8 : alpha;
		if (y>0 && y<bmp->h) 
			_alpha_pixel(bmp,x,y,color,_alpha-a);
		if (y>-1 && y<bmp->h-1) 
			_alpha_pixel(bmp,x,y+1,color,a);
 
		yf+=slope;
	}
#undef trunc
#undef frac
#undef invfrac
}


void aa_vslope(Bitmap *bmp,float x1, float y1, float x2, float y2, int32 color, int _alpha) 
{
#define trunc(i) ((i)&0xffff0000)
#define frac(i) ((i)&0x0000ffff)
#define invfrac(i) (0xffff-((i)&0x0000ffff))
	int y,slope;
	int yend,xend,ygap,xf;
	int alpha; int tclip=0;
	float fslope;
	long fy1=ftofix(y1),fx1=ftofix(x1),
		 fy2=ftofix(y2),fx2=ftofix(x2);

	int iy1 = (int)(y1),iy2 = (int)(y2),
		ix1 = (int)(x1),ix2 = (int)(x2);

	if (y2==y1) 
		return;
	if (y2<y1) 
	{
		UGLYFLOATSWAP(y1,y2); 
		UGLYFLOATSWAP(x2,x1); 
	}
	if ((x1<0 && x2<0) || (x1>=bmp->w && x2>=bmp->w)) 
		return;
	if ((y1<0 && y2<0) || (y1>=bmp->h && y2>=bmp->h)) 
		return;
	fslope=((x2-x1)/(y2-y1));
	slope=ftofix(fslope);
	//if (y1<0) {x1+=-y1*fslope; y1=0; tclip=1;}


	//Do first endpoint
	yend = trunc(fy1+0x8000);
	xend = fx1 + (slope*(yend-fy1)>>16);

	ygap = invfrac(fy1+0x8000);
	ix1=fixtoi(xend);
	iy1=fixtoi(yend);
	//if (!tclip) {
		alpha_pixel(bmp,ix1,iy1,color,(invfrac(xend)>>8)*(ygap>>8)*_alpha>>16);
		alpha_pixel(bmp,ix1+1,iy1,color,(frac(xend)>>8)*(ygap>>8)*_alpha>>16);
	//}
	xf=xend+slope;
	//Do second endpoint
	yend = trunc(fy2+0x8000);
	xend = fx2 + (slope*(yend-fy2)>>16);

	ygap = frac(fy2-0x8000);
	ix2=fixtoi(xend);
	iy2=fixtoi(yend);
	
	alpha_pixel(bmp,ix2,iy2,color,(invfrac(xend)>>8)*(ygap>>8)*_alpha>>16);
	alpha_pixel(bmp,ix2+1,iy2,color,(frac(xend)>>8)*(ygap>>8)*_alpha>>16);
	
	if (iy2 > bmp->h) iy2=bmp->h;
	//should optimize this inner loop like I did with hslope..
	for (y=iy1+1; y<iy2; y++) 
	{
		int a;
		alpha=(xf&0xffff)>>8;

		a=(_alpha!=255) ? alpha*_alpha>>8 : alpha;
		alpha_pixel(bmp,(xf>>16),y,color,_alpha-a);
		alpha_pixel(bmp,(xf>>16)+1,y,color,a);
 
		xf+=slope;
	}
}

void aa_line(Bitmap *bmp, float x1, float y1, float x2, float y2, uint32 color, int alpha) 
{
	if (fabsf(x1-x2) < fabsf(y1-y2)) 
		aa_vslope(bmp, x1, y1, x2, y2, color, alpha);
	else
		aa_hslope(bmp, x1, y1, x2, y2, color, alpha);
}

#undef ftofix
#undef itofix
#undef fixtoi
#undef trunc
#undef frac
#undef invfrac
