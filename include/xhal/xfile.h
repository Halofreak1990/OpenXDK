#ifndef	__XFILE_H__
#define	__XFILE_H__

#ifdef	__cplusplus
extern "C" {
#endif

#include	<openxdk.h>
//
//	Most of this is based on the excellent work dont by SNK
//

// **************************************************************************
//
//	Types and #defines
//
// **************************************************************************
typedef	int								HANDLE;		// normal handle
typedef u32								NTSTATUS;	// The usual NTSTATUS
typedef	char*							LPCSTR;

#ifndef	FALSE
#define	FALSE	0
#endif
#ifndef	TRUE
#define	TRUE	1
#endif
// Errors we might need
#define ERROR_NEGATIVE_SEEK				(131)
#define	ERROR_INVALID_NAME				(123)
#define	ERROR_OPEN_FAILED				(110)
#define	ERROR_DRIVE_LOCKED				(108)
#define	ERROR_HANDLE_DISK_FULL			(39)
#define ERROR_ALREADY_EXISTS			(183)
#define	ERROR_FILE_NOT_FOUND			(2)
#define	ERROR_TOO_MANY_OPEN_FILES		(4)
#define	ERROR_INVALID_HANDLE			(6)
#define NO_ERROR						(0)


#define	MAX_PATH						(2048)
#define	INVALID_HANDLE_VALUE			((HANDLE)-1)
#define INVALID_FILE_SIZE				((HANDLE)-1)
#define DELETE							(0x00010000L)

#define NT_SUCCESS(Status) ((NTSTATUS) (Status) >= 0)

#ifndef PAGE_SIZE
#define PAGE_SIZE			(0x1000)			//PAGE_SIZE
#endif 
#define ALIGN_SIZE			(0x10000)			// NT's allocation alignment size (64k)

// PAGE_ALIGN:
// Returns an address rounded down to the nearest page boundary.
// Differences from NT: None.
#define PAGE_ALIGN(Va)				((PVOID)((ULONG_PTR)(Va) & ~(PAGE_SIZE - 1)))


// Initializes an OBJECT_ATTRIBUTES.  I added this because it's familiar to
// NT kernel mode programmers.  I just changed it to the XBOX style.
// Works as if it were this function:
#define InitializeObjectAttributes( p, n, a, r ) { \
	(p)->RootDirectory = r; \
	(p)->Attributes = a; \
	(p)->ObjectName = n; \
	}


// Standard
#define FILE_FLAG_WRITE_THROUGH					(0x80000000)
#define FILE_FLAG_OVERLAPPED					(0x40000000)
#define FILE_FLAG_NO_BUFFERING					(0x20000000)
#define FILE_FLAG_RANDOM_ACCESS					(0x10000000)
#define FILE_FLAG_SEQUENTIAL_SCAN				(0x08000000)
#define FILE_FLAG_DELETE_ON_CLOSE				(0x04000000)
#define FILE_FLAG_BACKUP_SEMANTICS				(0x02000000)
#define FILE_FLAG_POSIX_SEMANTICS				(0x01000000)
#define FILE_FLAG_OPEN_REPARSE_POINT			(0x00200000)
#define FILE_FLAG_OPEN_NO_RECALL				(0x00100000)
												
// Flags for OBJECT_ATTRIBUTES::Attributes		
#define OBJ_INHERIT								(0x00000002L)
#define OBJ_PERMANENT							(0x00000010L)
#define OBJ_EXCLUSIVE							(0x00000020L)
#define OBJ_CASE_INSENSITIVE					(0x00000040L)
#define OBJ_OPENIF								(0x00000080L)
#define OBJ_OPENLINK							(0x00000100L)
#define OBJ_KERNEL_HANDLE						(0x00000200L)
#define OBJ_VALID_ATTRIBUTES					(0x000003F2L)
												
												
#define CREATE_NEW								(0x00000001)
#define CREATE_ALWAYS							(0x00000002)
#define OPEN_EXISTING							(0x00000003)
#define OPEN_ALWAYS								(0x00000004)
#define TRUNCATE_EXISTING						(0x00000005)
												
// CreateDisposition values						
#define FILE_SUPERSEDE							(0x00000000)
#define FILE_OPEN								(0x00000001)
#define FILE_CREATE								(0x00000002)
#define FILE_OPEN_IF							(0x00000003)
#define FILE_OVERWRITE							(0x00000004)
#define FILE_OVERWRITE_IF						(0x00000005)
#define FILE_MAXIMUM_DISPOSITION				(0x00000005)
												
#define GENERIC_READ							(0x80000000)
#define GENERIC_WRITE							(0x40000000)
//#define FILE_SHARE_READ							(0x00000001)
//#define FILE_SHARE_WRITE						(0x00000002)
												
#define	ERROR_INVALID_PARAMETER					(0x00000001)

#define FILE_DIRECTORY_FILE                     (0x00000001)
#define FILE_WRITE_THROUGH                      (0x00000002)
#define FILE_SEQUENTIAL_ONLY                    (0x00000004)
#define FILE_NO_INTERMEDIATE_BUFFERING          (0x00000008)
#define FILE_SYNCHRONOUS_IO_ALERT               (0x00000010)
#define FILE_SYNCHRONOUS_IO_NONALERT            (0x00000020)
#define FILE_NON_DIRECTORY_FILE                 (0x00000040)
#define FILE_CREATE_TREE_CONNECTION             (0x00000080)
#define FILE_COMPLETE_IF_OPLOCKED               (0x00000100)
#define FILE_NO_EA_KNOWLEDGE                    (0x00000200)
#define FILE_OPEN_FOR_RECOVERY                  (0x00000400)
#define FILE_RANDOM_ACCESS                      (0x00000800)
#define FILE_DELETE_ON_CLOSE                    (0x00001000)
#define FILE_OPEN_BY_FILE_ID                    (0x00002000)
#define FILE_OPEN_FOR_BACKUP_INTENT             (0x00004000)
#define FILE_NO_COMPRESSION                     (0x00008000)
#define FILE_RESERVE_OPFILTER                   (0x00100000)
#define FILE_OPEN_REPARSE_POINT                 (0x00200000)
#define FILE_OPEN_NO_RECALL                     (0x00400000)
#define FILE_OPEN_FOR_FREE_SPACE_QUERY          (0x00800000)
#define FILE_COPY_STRUCTURED_STORAGE            (0x00000041)
#define FILE_STRUCTURED_STORAGE                 (0x00000441)
#define FILE_VALID_OPTION_FLAGS                 (0x00ffffff)
#define FILE_VALID_PIPE_OPTION_FLAGS            (0x00000032)
#define FILE_VALID_MAILSLOT_OPTION_FLAGS        (0x00000032)
#define FILE_VALID_SET_FLAGS                    (0x00000036)

// DEVICE_TYPEs (I took a guess as to which the XBOX might have.)
#define FILE_DEVICE_CD_ROM						(0x00000002)
#define FILE_DEVICE_CD_ROM_FILE_SYSTEM			(0x00000003)
#define FILE_DEVICE_CONTROLLER					(0x00000004)
#define FILE_DEVICE_DISK						(0x00000007)
#define FILE_DEVICE_DISK_FILE_SYSTEM			(0x00000008)
#define FILE_DEVICE_FILE_SYSTEM					(0x00000009)
#define FILE_DEVICE_NULL						(0x00000015)
#define FILE_DEVICE_SCREEN						(0x0000001c)
#define FILE_DEVICE_SOUND						(0x0000001d)
#define FILE_DEVICE_UNKNOWN						(0x00000022)
#define FILE_DEVICE_VIDEO						(0x00000023)
#define FILE_DEVICE_VIRTUAL_DISK				(0x00000024)
#define FILE_DEVICE_FULLSCREEN_VIDEO			(0x00000034)
												
												
#define FILE_ATTRIBUTE_READONLY					(0x00000001)
#define FILE_ATTRIBUTE_HIDDEN					(0x00000002)
#define FILE_ATTRIBUTE_SYSTEM					(0x00000004)
#define FILE_ATTRIBUTE_DIRECTORY				(0x00000010)
#define FILE_ATTRIBUTE_ARCHIVE					(0x00000020)
#define FILE_ATTRIBUTE_NORMAL					(0x00000080)
#define FILE_ATTRIBUTE_TEMPORARY				(0x00000100)
#define FILE_FLAG_WRITE_THROUGH					(0x80000000)
#define FILE_FLAG_RANDOM_ACCESS					(0x10000000)

// NtCreateFile/NtOpenFile stuff
#define FILE_SUPERSEDED                 0x00000000
#define FILE_OPENED                     0x00000001
#define FILE_CREATED                    0x00000002
#define FILE_OVERWRITTEN                0x00000003
#define FILE_EXISTS                     0x00000004
#define FILE_DOES_NOT_EXIST             0x00000005


// Error codes
#define STATUS_SUCCESS					0x00000000
#ifndef STATUS_PENDING
#define STATUS_PENDING					0x00000103
#endif
#define STATUS_TIMER_RESUME_IGNORED		0x40000025
#define STATUS_UNSUCCESSFUL				0xC0000001
#define STATUS_UNRECOGNIZED_MEDIA		0xC0000014
#ifndef STATUS_NO_MEMORY
#define STATUS_NO_MEMORY				0xC0000017
#endif
#define STATUS_ALERTED					0x00000101
#define STATUS_USER_APC					0x000000C0

#define	FILE_BEGIN						(0x00000000)
#define	FILE_CURRENT					(0x00000001)
#define	FILE_END						(0x00000002)




// **************************************************************************
//
//	NtQueryInformationFile / NtSetInformationFile stuff
//	Types of information that can be set
//
// **************************************************************************
typedef enum _FILE_INFORMATION_CLASS {
	FileDirectoryInformation = 1,
	FileFullDirectoryInformation,
	FileBothDirectoryInformation,
	FileBasicInformation,		// known supported for "set" only; query???
	FileStandardInformation,	// known NOT supported; use NetworkOpen instead
	FileInternalInformation,
	FileEaInformation,
	FileAccessInformation,
	FileNameInformation,
	FileRenameInformation,
	FileLinkInformation,
	FileNamesInformation,
	FileDispositionInformation, // known to be supported; not tested
	FilePositionInformation,	// known to be supported; not tested
	FileFullEaInformation,
	FileModeInformation,
	FileAlignmentInformation,
	FileAllInformation,
	FileAllocationInformation,
	FileEndOfFileInformation,
	FileAlternateNameInformation,
	FileStreamInformation,
	FilePipeInformation,
	FilePipeLocalInformation,
	FilePipeRemoteInformation,
	FileMailslotQueryInformation,
	FileMailslotSetInformation,
	FileCompressionInformation,
	FileObjectIdInformation,
	FileCompletionInformation,
	FileMoveClusterInformation,
	FileQuotaInformation,
	FileReparsePointInformation,
	FileNetworkOpenInformation,		// known to be supported
	FileAttributeTagInformation,
	FileTrackingInformation
} FILE_INFORMATION_CLASS, *PFILE_INFORMATION_CLASS;

// **************************************************************************
//
//	Structs
//
// **************************************************************************
typedef struct _LARGE_INTEGER { 
	u32	LowPart; 
	u32	HighPart; 
} LARGE_INTEGER, *PLARGE_INTEGER; 


typedef struct  SString {
    unsigned short	Length;
    unsigned short	MaximumLength;
    char*			Buffer;
} SString, *PString;
typedef SString		ANSI_STRING, *PANSI_STRING;


typedef struct  SObject_Attributes {
	HANDLE			RootDirectory;
	PANSI_STRING	ObjectName;
	u32				Attributes;
} SObject_Attributes, *PObject_Attributes;


typedef struct  _IO_STATUS_BLOCK {
	//union {
		NTSTATUS	Status;
	//	PVOID		Pointer;
	//};

	u32				*Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;


typedef struct SSecurity_Attributes{
    u32		nLength;
    void*	lpSecurityDescriptor;
    u32		bInheritHandle;
} SSecurity_Attributes, *PSecurity_Attributes ;


typedef struct _OVERLAPPED {
    u32		Internal;
    u32		InternalHigh;
    u32		Offset;
    u32		OffsetHigh;
    HANDLE  hEvent;
} OVERLAPPED, *LPOVERLAPPED;



// File pointer information (SetFilePointer and such use this) Query/Set
typedef struct _FILE_POSITION_INFORMATION {
	LARGE_INTEGER	CurrentByteOffset;
} FILE_POSITION_INFORMATION, *PFILE_POSITION_INFORMATION;



// Access times and normal attributes
// Query/set?  Only Set is known to be supported.  Use
// FILE_NETWORK_OPEN_INFORMATION if you want to query this data.
typedef struct _FILE_BASIC_INFORMATION {
	LARGE_INTEGER	CreationTime;
	LARGE_INTEGER	LastAccessTime;
	LARGE_INTEGER	LastWriteTime;
	LARGE_INTEGER	ChangeTime;
	ULONG			FileAttributes;
} FILE_BASIC_INFORMATION, *PFILE_BASIC_INFORMATION;




// Access times and normal attributes
typedef struct _FILE_NETWORK_OPEN_INFORMATION 
{
	LARGE_INTEGER CreationTime;				// 000 Time file was created
	LARGE_INTEGER LastAccessTime;			// 008 Time file was last accessed
	LARGE_INTEGER LastWriteTime;			// 010 Time file was last opened for writing?
	LARGE_INTEGER ChangeTime;				// 018 Time file was last changed?
	LARGE_INTEGER AllocationSize;			// 020 Size of the file in the file system (including slack space)
	LARGE_INTEGER EndOfFile;				// 028 What we'd normally call the file size
	ULONG FileAttributes;					// 030 File attributes
	ULONG Unknown;							// 034 Unknown
} FILE_NETWORK_OPEN_INFORMATION, *PFILE_NETWORK_OPEN_INFORMATION;



HANDLE	CreateFile(char* lpFilename,
					u32		dwDesiredAccess, 
					u32		dwShareMode,
					SSecurity_Attributes	*lpSecurityAttributes,
					u32		dwCreationDisposition,
					u32		dwFlagsAndAttributes,
					HANDLE	hTemplateFile
					);
int	ReadFile(	HANDLE	hFile,					// file handle
				void*	lpBuffer,				// Dest buffer to put file
				u32		nNumberOfBytesToRead,	// read "n" bytes
				u32*	lpNumberOfBytesRead,	// pointer to a place to store bytes read
				LPOVERLAPPED lpOverlapped		// NULL unless overlap
			);

int WriteFile(	HANDLE			hFile, 
				PVOID			lpBuffer,
				u32				nNumberOfBytesToWrite,
				u32*			lpNumberOfBytesWritten,
				LPOVERLAPPED	lpOverlapped
				);

int	CloseHandle( HANDLE Handle );
int	GetFileSizeEx(	HANDLE hFile, PLARGE_INTEGER lpFileSize);
int	SetFilePointerEx( HANDLE hFile, LARGE_INTEGER liDistanceToMove, PLARGE_INTEGER lpNewFilePointer, DWORD dwMoveMethod);



char* GetLastErrorMessage( void );
void SetLastError( u32 ErrorCode );

LARGE_INTEGER	AddU64( PLARGE_INTEGER  A,PLARGE_INTEGER  B );


#ifdef	__cplusplus
};
#endif
#endif	//__XFILE_H__




