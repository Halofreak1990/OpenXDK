#ifndef _SYS_DIRENT_H
#define _SYS_DIRENT_H

struct dirent 
{
	unsigned long	 d_ino;
	unsigned short d_reclen;
	unsigned short d_namlen;
	char		       d_name[0x100];
};

typedef struct _DIR
{
	unsigned int  handle;
	int           firstTime;
	char          pathName[0x100];
	struct dirent d;
} DIR;

DIR *opendir (const char *);
struct dirent *readdir (DIR *);
void rewinddir (DIR *);
int closedir (DIR *);

#endif
