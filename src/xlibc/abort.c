// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : _memccpy.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

// Abort is supposed to return to the OS with an error... we'll just crash...
// We could PRINT an error to the screen however....
void abort( void )
{
	while(1){
	};
}
