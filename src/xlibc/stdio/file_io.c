// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : file_io.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include	<stdio.h>


// ********************************************************
//
// Name:		_open( name, rwmode, permission )
// Function:   	These are just wrappers around the more 
//				complicated xhal stuff. 
//				permission isnt used just now
//
// ********************************************************
int _open( char *filename, int oflag, int permission )
{
	int	   RW_flags=0;
	int	   open_flags=0;
	int	   sys_flags=0;
	HANDLE handle;

	//
	// Translate flags and settings 
	//
	if( (oflag&_O_RDONLY) != 0 ){
		RW_flags|=GENERIC_READ;
		sys_flags |= FILE_FLAG_RANDOM_ACCESS;
		open_flags = OPEN_EXISTING;
	}
	if( (oflag&_O_WRONLY) != 0 ){
		RW_flags|=GENERIC_WRITE;
		sys_flags |= FILE_FLAG_RANDOM_ACCESS;
		open_flags = OPEN_EXISTING;
	}

	if( (oflag&_O_RDWR) != 0 ){
		RW_flags|=GENERIC_READ|GENERIC_WRITE;
		sys_flags |= FILE_FLAG_RANDOM_ACCESS;
		open_flags = OPEN_EXISTING;
	}


	//
	// File creation flags
	//
	
	// return an error if file exsists
	if( (oflag&(_O_CREAT | _O_EXCL)) == (_O_CREAT | _O_EXCL) ){
		open_flags=CREATE_NEW;
	}
	// Create a new file, or truncate existing file.
	if( (oflag&(_O_CREAT | _O_TRUNC)) == (_O_CREAT | _O_TRUNC) ){
		open_flags=CREATE_ALWAYS;
	}
	// Create a new file, or truncate existing file.
	if( (oflag&(_O_CREAT | _O_TEMPORARY)) == (_O_CREAT | _O_TEMPORARY) ){
		open_flags=CREATE_NEW;
		sys_flags|=FILE_FLAG_DELETE_ON_CLOSE;
	}
	


//	handle = CreateFile(	"\\??\\D:\\test.txt",
//	handle = CreateFile(	"D:\\test.txt",
	handle = CreateFile(	filename,
							RW_flags, 
							0,
							NULL,
							open_flags,
							sys_flags,
							NULL
						);

	return (int)handle;
}


// ********************************************************
//
// Name:		_read( handle, buffer, count );
// Function:   	Wrapper round NT read function
//
// ********************************************************
int _read( int handle, void* buffer, unsigned int count )
{
	unsigned int	AmountRead;
	int status = ReadFile( (HANDLE)handle,  buffer, count, &AmountRead, NULL );
	
	return AmountRead;
}


// ********************************************************
//
// Name:		_read( handle, buffer, count );
// Function:   	Wrapper round NT read function
//
// ********************************************************
int _write( int handle, void* buffer, unsigned int count )
{
	unsigned int	AmountWritten;
	int status = WriteFile( (HANDLE)handle,  buffer, count, &AmountWritten, NULL );
	
	return AmountWritten;
}


// ********************************************************
//
// Name:		_close( int handle )
// Function:   	Wrapper round NT close function
//
// ********************************************************
int _close( int handle )
{
	return CloseHandle( (HANDLE)handle );
}


// ********************************************************
//
// Name:		_lseek( int handle, u32 offset, int base )
// Function:   	Wrapper round NT SetFilePointerEx function
//
// ********************************************************
int _lseek( int handle, u32 offset, int base )
{
	int				flags;
	LARGE_INTEGER	Distance;
	LARGE_INTEGER	NewLocation;

	switch( base ){
		case	SEEK_SET:	flags = FILE_BEGIN;	break;
		case	SEEK_CUR:	flags = FILE_CURRENT; break;
		case	SEEK_END:	flags = FILE_END; break;
	}
	Distance.u.HighPart = 0;
	Distance.u.LowPart = offset;

	NewLocation.u.HighPart=0;
	NewLocation.u.LowPart=0;

	SetFilePointerEx( (HANDLE)handle, Distance, &NewLocation, flags );
	return NewLocation.u.LowPart;
}


