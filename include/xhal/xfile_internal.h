// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xfile_internal.h
// *
// * note : internal stuff for xfile
// *
// ******************************************************************

#ifndef	__XFILE_INTERNAL_H__
#define	__XFILE_INTERNAL_H__

#ifdef	__cplusplus
extern "C" {
#endif

// **************************************************************************
//
//	Types and #defines
//
// **************************************************************************
//typedef	int								HANDLE;		// normal handle
//typedef u32								NTSTATUS;	// The usual NTSTATUS




// CreateDisposition values						
#define FILE_SUPERSEDE							(0x00000000)
#define FILE_OPEN								(0x00000001)
#define FILE_CREATE								(0x00000002)
#define FILE_OPEN_IF							(0x00000003)
#define FILE_OVERWRITE							(0x00000004)
#define FILE_OVERWRITE_IF						(0x00000005)
#define FILE_MAXIMUM_DISPOSITION				(0x00000005)

//#define FILE_SHARE_READ							(0x00000001)
//#define FILE_SHARE_WRITE						(0x00000002)
												

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

// Flags for OBJECT_ATTRIBUTES::Attributes		
#define OBJ_INHERIT								(0x00000002L)
#define OBJ_PERMANENT							(0x00000010L)
#define OBJ_EXCLUSIVE							(0x00000020L)
#define OBJ_CASE_INSENSITIVE					(0x00000040L)
#define OBJ_OPENIF								(0x00000080L)
#define OBJ_OPENLINK							(0x00000100L)
#define OBJ_KERNEL_HANDLE						(0x00000200L)
#define OBJ_VALID_ATTRIBUTES					(0x000003F2L)
										
												




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

typedef struct  SString {
    unsigned short	Length;
    unsigned short	MaximumLength;
    char*			Buffer;
} SString, *PString;
typedef SString;


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

LARGE_INTEGER	AddU64( PLARGE_INTEGER  A,PLARGE_INTEGER  B );

#ifdef	__cplusplus
};
#endif
#endif	//__XFILE_INTERNAL_H__
