#ifndef	__DEFS__
#define	__DEFS__

typedef	unsigned char		byte;
typedef	unsigned char		u8;
typedef	signed char			s8;
typedef	unsigned short		u16;
typedef	signed short		s16;
typedef	unsigned int		u32;
typedef	signed int			s32;
typedef	signed __int64		s64;
typedef	unsigned __int64	u64;



#ifndef	NULL
#define	NULL			0x00
#endif

//
// LIBC basics
//
//typedef	unsigned int		size_t;
#define	op_t	unsigned long int
#define OPSIZ	(sizeof(op_t))
/*
#define	CONST			const*/
#define	__CONSTVALUE
#define	__alloca		_alloca			// MSDEV has a built in _alloca


int	isascii(int c);


#endif	//__DEFS__
