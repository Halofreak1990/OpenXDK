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
#include "xgfx2d/drawprim.h"


void clear(Bitmap *bmp, uint32 col) {
	int y;
	if (col==0) {
		for (y=0; y<bmp->h; y++) {
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



