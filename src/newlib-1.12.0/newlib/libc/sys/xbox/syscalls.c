#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <hal/xbox.h>
#include <hal/fileio.h>

#define	O_RDONLY    0x00000000
#define	O_WRONLY    0x00000001
#define	O_RDWR      0x00000002
#define	O_APPEND    0x00000008
#define	O_CREAT     0x00000200
#define	O_TRUNC     0x00000400
#define	O_EXCL      0x00000800
#define O_TEMPORARY 0x00001000
#define O_BINARY    0x00010000
#define O_TEXT      0x00020000
#define O_NOINHERIT	0x00040000

#define SEEK_SET        0
#define SEEK_CUR        1
#define SEEK_END        2

struct tms 
{
	clock_t tms_utime;              /* user time */
	clock_t tms_stime;              /* system time */
	clock_t tms_cutime;             /* user time, children */
	clock_t tms_cstime;             /* system time, children */
};

//char *__env[1] = { 0 };
//char **environ = __env;

/*
 * Convert a XBOX time format to Unix time.
 * If not NULL, 'remainder' contains the fractional part of the filetime,
 * in the range of [0..9999999] (even if time_t is negative).
 * Borrowed from synce/libwine/wine.c
 */
time_t XBOXFileTimeToUnixTime(LARGE_INTEGER xboxTime, DWORD *remainder)
{
	unsigned int a0;    /* 16 bit, low    bits */
	unsigned int a1;    /* 16 bit, medium bits */
	unsigned int a2;    /* 32 bit, high   bits */
	unsigned int r;     /* remainder of division */
	unsigned int carry; /* carry bit for subtraction */
	int negative;       /* whether a represents a negative value */
	
	/* Copy the time values to a2/a1/a0 */
	a2 =  (unsigned int)xboxTime.u.HighPart;
	a1 = ((unsigned int)xboxTime.u.LowPart) >> 16;
	a0 = ((unsigned int)xboxTime.u.LowPart) & 0xffff;

	/* Subtract the time difference */
	if (a0 >= 32768           ) a0 -=             32768        , carry = 0;
	else                        a0 += (1 << 16) - 32768        , carry = 1;
	
	if (a1 >= 54590    + carry) a1 -=             54590 + carry, carry = 0;
	else                        a1 += (1 << 16) - 54590 - carry, carry = 1;

	a2 -= 27111902 + carry;
	
	/* If a is negative, replace a by (-1-a) */
	negative = (a2 >= ((unsigned int)1) << 31);
	if (negative)
	{
		/* Set a to -a - 1 (a is a2/a1/a0) */
		a0 = 0xffff - a0;
		a1 = 0xffff - a1;
		a2 = ~a2;
	}

	/* Divide a by 10000000 (a = a2/a1/a0), put the rest into r.
	   Split the divisor into 10000 * 1000 which are both less than 0xffff. */
	a1 += (a2 % 10000) << 16;
	a2 /=       10000;
	a0 += (a1 % 10000) << 16;
	a1 /=       10000;
	r   =  a0 % 10000;
	a0 /=       10000;
	
	a1 += (a2 % 1000) << 16;
	a2 /=       1000;
	a0 += (a1 % 1000) << 16;
	a1 /=       1000;
	r  += (a0 % 1000) * 10000;
	a0 /=       1000;
	
	/* If a was negative, replace a by (-1-a) and r by (9999999 - r) */
	if (negative)
	{
		/* Set a to -a - 1 (a is a2/a1/a0) */
		a0 = 0xffff - a0;
		a1 = 0xffff - a1;
		a2 = ~a2;

		r  = 9999999 - r;
	}

	if (remainder) *remainder = r;

	/* Do not replace this by << 32, it gives a compiler warning and it does
	   not work. */
	return ((((time_t)a2) << 16) << 16) + (a1 << 16) + a0;
}
    
int close(int fd)
{
	return XCloseHandle(fd);
}

int execve(char *name, char **argv, char **env)
{
	// one of these days I will write code that kicks
	// off a new XBE file, but for now, it isn't supported
	errno = EACCES;
	return -1;
}

int fork() 
{
	// no real notion of fork supported yet... 
	// maybe later, but not yet.
	errno = EAGAIN;
	return -1;
}

int fstat(int fd, struct stat *st)
{
	NTSTATUS                      status;
	IO_STATUS_BLOCK               ioStatusBlock;
	FILE_NETWORK_OPEN_INFORMATION networkInfo;
	
	status = NtQueryInformationFile(
		(void*)fd, 
		&ioStatusBlock,
		&networkInfo, 
		sizeof(networkInfo), 
		FileNetworkOpenInformation);
	if (!NT_SUCCESS(status))
	{
		errno = RtlNtStatusToDosError(status);
		return -1;
	}
		
	if (st)
	{
		st->st_dev = 0;   // default it to zero for now
		st->st_mode = 0;  // default it to zero for now
		st->st_ino = 0;   // surely we don't care, do we?
		st->st_nlink = 0; // default to zero
		st->st_uid = 0;   // surely we don't care, do we?
		st->st_gid = 0;   // surely we don't care, do we?
		st->st_rdev = 0;  // dunno what this is... 
		st->st_size = (unsigned int)networkInfo.EndOfFile.u.LowPart;
		st->st_atime = XBOXFileTimeToUnixTime(networkInfo.LastAccessTime, NULL);
		st->st_mtime = XBOXFileTimeToUnixTime(networkInfo.LastWriteTime, NULL);
		st->st_ctime = XBOXFileTimeToUnixTime(networkInfo.ChangeTime, NULL);

		// stdin, stdout and stderr are all character devices
		if (fd == 0 || fd == 1 || fd == 2)
			st->st_mode = S_IFCHR;
		else
		{
			if (networkInfo.FileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				st->st_mode = S_IFDIR;
			else if (networkInfo.FileAttributes & FILE_ATTRIBUTE_DEVICE)
				st->st_mode = S_IFBLK;
			else
				st->st_mode = S_IFREG;
		}
	}
	return 0;
}

int getpid()
{
	// return a made-up pid.  Maybe I could get 
	// this from the XBOX kernel, but really, who cares?
	return 2340;
}

int isatty(int fd)
{
	struct stat buf;
	if (fstat(fd, &buf) < 0)
		return 0;
	if (S_ISCHR(buf.st_mode))
		return 1;
	return 0;
}

int kill(int pid, int sig)
{
	// nah... no support for killing yet.
	errno = EINVAL;
	return -1;
}

int link(char *old, char *new)
{
	// XBOX doesn't support symbolic links (I think), so
	// we don't do anything here.
	errno = EMLINK;
	return -1;
}

int lseek(int fd, int offset, int base)
{
	int flags = 0;
	int newPosition = 0;;

	switch(base)
	{
		case SEEK_SET: flags = FILE_BEGIN; break;
		case SEEK_CUR: flags = FILE_CURRENT; break;
		case SEEK_END: flags = FILE_END; break;
	}

	errno = XSetFilePointer(fd, offset, &newPosition, flags);
	if (errno != STATUS_SUCCESS)
		return -1;
	else
		return newPosition;
}

int open(char *filename, int flags)
{
	int handle;
	int accessFlags = 0;
	int shareFlags = 0;
	int createFlags = 0;
	int sysFlags = 0;

	// now the O_TEXT and O_BINARY flags may have been set, but 
	// we don't really care about them, so lets mask them out
	flags &= 0x0000FFFF;
	
	switch (flags & (O_RDONLY | O_WRONLY | O_RDWR))
	{
	case O_RDONLY:
		accessFlags = GENERIC_READ;
		break;
	case O_WRONLY:
		accessFlags = GENERIC_WRITE;
		break;
	case O_RDWR:
		accessFlags = GENERIC_READ | GENERIC_WRITE ;
		break;
	default:
		errno = EINVAL;
		return -1;
	}
	switch (flags & (O_CREAT | O_TRUNC))
	{
	case 0:
		createFlags = OPEN_EXISTING;
		break;
	case O_CREAT:
		createFlags = CREATE_ALWAYS;
		break;
	case O_CREAT | O_TRUNC:
		createFlags = CREATE_ALWAYS;
		break;
	case O_TRUNC:
		createFlags = TRUNCATE_EXISTING;
		break;
	default:
		errno = EINVAL;
		return -1;
	}
	sysFlags   = FILE_FLAG_RANDOM_ACCESS;
	shareFlags = FILE_SHARE_READ | FILE_SHARE_WRITE;

	if (flags & O_TEMPORARY)
		sysFlags |= FILE_FLAG_DELETE_ON_CLOSE;

	errno = XCreateFile(&handle, filename, accessFlags, shareFlags, createFlags, sysFlags);
	if (errno != STATUS_SUCCESS)
		return -1;
	else
		return handle;
}

int read(int fd, char *ptr, int len)
{
	unsigned int amountRead;
	errno = XReadFile(fd, ptr, len, &amountRead);
	if (errno != STATUS_SUCCESS)
		return -1;
	else
		return amountRead;
}

// sbrk is not implemented because we are using the WIN32
// routines defined in newlib/libc/stdlib/mallocr.c
// Specifically, check out the VirtualAlloc/VirtualFree
// functions at the end of this file
//char *sbrk(int incr)
//{
//	return (char *)0;
//}

int stat(const char *filename, struct stat *st)
{
	int fd = open((char *)filename, O_RDONLY);
	if (fd != -1)
	{
		int rc = fstat(fd, st);
		close(fd);
		return rc;
	}
	else
		return -1;
}

clock_t times(struct tms *buf)
{
	clock_t tc = XGetTickCount();
	if (buf)
	{
		buf->tms_utime = tc;
		buf->tms_stime = tc;
		buf->tms_cutime = tc;
		buf->tms_cstime = tc;
	}
	return tc;
}

int unlink(char *filename)
{
	errno = XDeleteFile(filename);
	if (errno != STATUS_SUCCESS)
		return -1; 
	else
		return 0;
}

int wait(int *status)
{
	// not much point waiting for other processes if
	// we can't actually kick them off!
	errno = ECHILD;
	return -1;
}

int write(int fd, char *ptr, int len)
{
	unsigned int amountWritten;
	errno = XWriteFile(fd, ptr, len, &amountWritten);
	if (errno != STATUS_SUCCESS)
		return -1;
	else
		return amountWritten;
}

void _exit()
{
	XReboot();
}

// ****************************************************************************
// *  Routines required to support the malloc routines in libc\stdlib\mallocr.c
// ****************************************************************************

unsigned int NTAPI VirtualAlloc(void *lpAddress, unsigned long dwSize, unsigned int flAllocationType, unsigned int flProtect)
{
	NtAllocateVirtualMemory(&lpAddress, 0, &dwSize, flAllocationType, flProtect);
	return (unsigned int)lpAddress;
}

int NTAPI VirtualFree(void *lpAddress, unsigned long dwSize, unsigned int dwFreeType)
{
	return NtFreeVirtualMemory(lpAddress, &dwSize, dwFreeType);
}

unsigned int NTAPI VirtualQuery(const void *lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, unsigned int dwLength)
{
	return NtQueryVirtualMemory((HANDLE)lpAddress, lpBuffer);
}

int NTAPI LocalAlloc(unsigned int flags, unsigned int size)
{
	return VirtualAlloc(0, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
}

int NTAPI LocalFree(int address)
{
	return VirtualFree((void*)address, 0, 0);
}

void ASSERT(int blah)
{
}
