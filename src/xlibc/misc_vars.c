#include	<ansidecl.h>
#include	<stdlib.h>

int 		errno;
u8			_Nan[8]={0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF };		// define an __int64 for a NAN
u8			_Inf[8]={0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x7F };		// INF




//
// abort does NOT return, but is suposed to "quit" the application with error code 3
// We will just "CRASH"  We could "print"  ABORT to the screen
//
void	abort( void )
{
	while(1){
	}
}