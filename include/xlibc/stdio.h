#ifndef	__STDIO_H__
#define	__STDIO_H__	1


# ifdef __cplusplus
extern "C" {
# endif

//int sprintf(char*, const char *format, ...);
int __cdecl sprintf(char *, const char *, ...);

//#include	<tamtypes.h>
#include	<stddef.h>
#include	<features.h>

#define O_RDONLY	0x0001
#define O_WRONLY	0x0002
#define O_RDWR		0x0003
#define O_NBLOCK	0x0010
#define O_APPEND	0x0100
#define O_CREAT		0x0200
#define O_TRUNC		0x0400
#define O_NOWAIT	0x8000

#define SEEK_SET    0
#define SEEK_CUR    1
#define SEEK_END    2

int fileio_init();
int fio_open( u8 *fname, int mode);
int fio_close( int fd);
int fio_read_intr( void *data_raw);
int fio_read( int fd, void *buff, int buff_size);
int fio_write( int fd, void *buff, int buff_size);
int fio_lseek( int fd, u32 pos, int mode);


int nprintf(const char *format, ...);
int printf(const char *format, ...);
//int sprintf(char*, const char *format, ...);

# ifdef __cplusplus
}
# endif

#endif 			// __STDIO_H__
