/******************************************************************************/
/*																              */
/* File: misc.cpp                                                             */
/* Author: bkenwright@xbdev.net                                               */
/* Desc: Misc functions, making our usb/gamepad code lib independent          */
/*                                                                            */
/******************************************************************************/


#include "ohci.h"
#include "misc.h"



/******************************************************************************/
/*                                                                            */
/* Debug Function                                                             */
/*                                                                            */
/* Its a simple, but useful function to provide essential feedback during     */
/* the early development stages....especially when your developing an app     */
/* like the ohci-usb :-/                                                      */
/*                                                                            */
/******************************************************************************/


//#include <stdlib.h>
//#include <stdio.h>

//extern void op_txt(char* str); // top of main.cpp

char buf[500];
void dbg(char* str)
{
	//FILE *fp = fopen("d:\\output.txt", "a+");
	//fprintf(fp, "%s", str);
	//fclose(fp);

	//char buffer[500];
	//sprintf(buffer, "%s", str);
	//op_txt(str);
}// End dbg(..)




/******************************************************************************/

// Not the best timming algorithm, but it will do for now :)

void get_cpu_clock(unsigned long& clock_high_, unsigned long& clock_low_)
{
	unsigned long high_buf;
	unsigned long low_buf;
	_asm{
		push eax
		push edx
		rdtsc		
		mov	high_buf, edx
		mov	low_buf, eax
		pop eax
		pop edx
	}
	clock_high_ = high_buf;
	clock_low_ = low_buf;
}// End of get_cpu_clock(..)

static unsigned long dwTickCount = 0;

/******************************************************************************/
/* Small Bug?                                                                 */
/* In the openxdk, when I tried to divide a __int64 number I was confronted   */
/* with a link error...as long div insn't implemented yet..  So I instead     */
/* used an approx of the cpu speed (e.g. 7330000) and used a shift division   */
/* which is good enough for our ohci-usb delays                               */
/******************************************************************************/

//unsigned __int64 MyGetTickCount()
unsigned int MyGetTickCount()
{
	unsigned __int64 value;

	unsigned long h, l;
	get_cpu_clock(h, l);

	value = h;
	value = value << 32;
	value = value | l;

	//unsigned __int64 div = 733000;
	//unsigned __int64 vv = value/div;
	
	// e.g.
	// 1<<19 == 524288
	// 1<<20 == 1048576

	value = value >> 19;                     // You can't get a division of 
	                                         // 733000 so I chose the closest
	                                         // value I could using a divide
	                                         // shift.

	//unsigned int div = 733000;
	//unsigned int vv = value/div;

	unsigned int vv = (int) value;

	return (unsigned int)vv;
}// End of MyGetTickCount(..)

/******************************************************************************/


// Might want to look into using this kernel api at a later date for xSleep(..)
// extern "C" void __stdcall KeDelayExecutionThread(__u32 a, __u32 b, __u32 c);


void xSleep( long timemilliseconds )
{
	//Sleep(timemilliseconds);

	unsigned __int64 nowTime = MyGetTickCount();
	unsigned __int64 oldTime = MyGetTickCount();

	while( nowTime < (oldTime + timemilliseconds) )
		nowTime = (int)MyGetTickCount();

}



void *xmemcpy(void *dest, const void *src, size_t n)
{
	//memcpy(dest, src, n);

	unsigned char * from = (unsigned char*)src;
	unsigned char * to = (unsigned char*)dest;

	// Not optimised or checking for errors!
	for( unsigned int i=0; i<n; i++ )
	{
		to[i] = from[i];
	}

	return 0; // skip error checking
}

/*
NTSYSAPI EXPORTNUM(165) PVOID NTAPI MmAllocateContiguousMemory
(
	IN ULONG NumberOfBytes
);
*/


extern "C" __u32 __stdcall MmAllocateContiguousMemory(__u32 a);

void *xmalloc(size_t size)
{
	//return malloc(size);
	return (void*)MmAllocateContiguousMemory( size );
}

void *xmemset(void *s, int c, size_t n)
{

	//memset(s, c, n);

	unsigned char * what = (unsigned char*)s;

	// Not optimised or checking for errors!
	for( unsigned int i=0; i<n; i++ )
	{
		what[i] = c;
	}

	return  0; // skip error checking
}



/******************************************************************************/
/*
  These are kernel api's!  We really really need these so that we can get
  the physcial memory location.  As when we pass the memory location to 
  our ohci registers, it gets the virtual address.  As you have to remember
  where working in protected mode!

  A small example is as follows:

  __u32 aa = MxmallocateContiguousMemory( 4*4 );
             MmLockUnlockBufferPages( aa, 4*4, 0);
  __u32 cc = MmGetPhysicalAddress( aa );

  And here is what the values of aa and cc would look like:
  aa = 0x00f34420;
  cc = 0x00334420;

  They are different!  You can check this in a number of ways...using a debugger
  or sprint(..) and write the values to file.
*/
/******************************************************************************/



extern "C" __u32 __stdcall MmLockUnlockBufferPages(__u32 MemoryAddress, __u32 NumberOfBytes, __u32 a);


// Don't use this kernel api - but I've put it's declaration here, just
// incase we decide to use it later.
// extern "C" void __stdcall MmMapIoSpace( __u32 PhysicalAddress, __u32 NumberOfBytes, __u32 CacheType );


//#include <openxdk.h>
extern "C" __u32 __stdcall MmGetPhysicalAddress(__u32  BaseAddress);



/*
NTSYSAPI EXPORTNUM(173) PVOID NTAPI MmGetPhysicalAddress
(
	IN PHYSICAL_ADDRESS BaseAddress
}
*/


__u32 xMmGetPhysicalAddress(__u32  BaseAddress)
{
	return MmGetPhysicalAddress(BaseAddress);
}


/*
NTSYSAPI EXPORTNUM(175) PVOID NTAPI MmLockUnlockBufferPages
(
	IN PHYSICAL_ADDRESS BaseAddress,
	IN ULONG            SizeBytes,
	IN ULONG			OPTIONAL
);
*/


void xMmLockUnlockBufferPages(__u32 MemoryAddress, __u32 NumberOfBytes, __u32 a)
{
	MmLockUnlockBufferPages( MemoryAddress, NumberOfBytes, a);
}


