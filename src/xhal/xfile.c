// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xfile.c
// *
// * note : XBox File Access
// *
// ******************************************************************
#include "openxdk.h"
#include "xhal/xfile_def.h"

u32 LastErrorCode=1;

u32 ErrorCodes[] =
{
    ERROR_HANDLE_DISK_FULL,
    ERROR_INVALID_NAME,
    ERROR_OPEN_FAILED,
    ERROR_DRIVE_LOCKED,
    ERROR_FILE_NOT_FOUND,
    ERROR_TOO_MANY_OPEN_FILES,
    ERROR_INVALID_HANDLE,
    0,  
};

char Errors[][128] =
{
    "The disk is full.",
    "The filename, directory name, or volume label syntax is incorrect.",
    "The system cannot open the device or file specified.",
    "The disk is in use or locked by another process.",
    "The system cannot find the file specified.",
    "The system cannot open the file.",
    "The handle is invalid.",
    "No error found, or unknown code",
};
                        
// ******************************************************************
// * GetLastErrorMessage
// ******************************************************************
// *
// * retrieve a text version of a the last error
// *
// ******************************************************************
char* GetLastErrorMessage( void )
{
    int i=0;

    while(ErrorCodes[i] != LastErrorCode)
    {
        i++;
        if(ErrorCodes[i]==0)
            break;
    }

    return Errors[i];
}

// ******************************************************************
// * SetLastError
// ******************************************************************
// *
// * set the last error code
// *
// ******************************************************************
void SetLastError( u32 ErrorCode )
{
    LastErrorCode = ErrorCode;
}

// ******************************************************************
// * InitStringKnownLength
// ******************************************************************
// *
// * Initialize a string whose length is already known - this is an 
// * optimized version of RtlInitAnsiString in the case that we know
// * the length already.
// *
// ******************************************************************
static VOID InitStringKnownLength
(
    OUT PANSI_STRING  String,
    IN  PCHAR         Buffer,
    IN  ULONG         Length
)
{
    String->Buffer = Buffer;
    String->Length = (u16)Length;
    String->MaximumLength = (u16)Length + 1;
}

// ******************************************************************
// * InitStringConstant
// ******************************************************************
// *
// * Initialize a string whose parameter is a *constant* string
// * (IE, sizeof() must work on it).
// *
// ******************************************************************
#define InitStringConstant(x, y) InitStringKnownLength((x), (y), sizeof(y) - 1)

// ******************************************************************
// * AdjustStringForward
// ******************************************************************
// *
// * Moves an ANSI_STRING forward some number of characters
// *
// ******************************************************************
static VOID AdjustStringForward(PANSI_STRING String, ULONG Length )
{
    String->Buffer += Length;
    String->Length -= (u16) Length;
    String->MaximumLength -= (u16) Length;
}

// ******************************************************************
// * Win32FixPath
// ******************************************************************
// *
// * Convert a Win32-style path into an NT-style path.  D:\ is always
// * considered to be the "current" directory.  lpOutString becomes
// * an already-initialized ANSI_STRING, which the caller can use to
// * avoid doing another RtlInitAnsiString, which is another strlen()
// *
// * Examples:
// *
// * D:\default.xbe               -> \??\D:\default.xbe   
// * .\default.xbe                -> \??\D:\default.xbe   
// * \default.xbe                 -> \??\D:\default.xbe   
// * default.xbe                  -> \??\D:\default.xbe   
// * \\.\D:                       -> \??\D:   
// * \\.\GLOBALROOT\Device\CdRom0 -> \Device\CdRom0   
// *    
// ******************************************************************
static VOID Win32FixPath
(
    PANSI_STRING  OutString,
    PCHAR         lpFixedFilename,
    char*         lpFilename,
    u32           dwMaximumLength
)
{
    ANSI_STRING InString;
    ANSI_STRING TempString;
    ANSI_STRING ConstString;
    u32         Length;

    // If dwMaximumLength is zero, don't bother.
    if (!dwMaximumLength)
        return;

    // If OutString is NULL, just use a temporary string.
    if (!OutString)
        OutString = &TempString;

    // Calculate the length of the input filename
    RtlInitAnsiString((void*)&InString, lpFilename);
    Length = InString.Length;

    // Initialize the output string
    OutString->Buffer = (PCHAR) lpFixedFilename;
    OutString->Length = 0;
    OutString->MaximumLength = dwMaximumLength;

    // Case \\.\GLOBALROOT\Device\MyDevice (to allow mangling bypass)
    // Windows 2000 and XP support this, so let's support it too.
    // Check the \ at the end because we shouldn't translate \\.\GLOBALROOT2
    // or similar.
    if ((Length >= 15) &&
        (RtlCompareMemory(lpFilename, "\\\\.\\GLOBALROOT\\", 15) == 15))
    {
        // Copy the filename without \\.\GLOBALROOT (leave the trailing \)
        AdjustStringForward(&InString, 14);
        RtlCopyString(  OutString, &InString);
    }
    // Case \\.\D: (-> \??\D:)
    else if ((Length >= 4) &&
        (RtlCompareMemory(lpFilename, "\\\\.\\", 4) == 4))
    {
        // Copy the filename...
        RtlCopyString(OutString, &InString);

        // Then replace '\\.\' with '\??\'
        OutString->Buffer[1] = '?';
        OutString->Buffer[2] = '?';
    }
    // Case X:\FILENAME.EXT (-> \??\X:\FILENAME.EXT)
    else if ( (Length >= 3) &&
              (((lpFilename[0] >= 'A') && (lpFilename[0] <= 'Z')) ||
              ((lpFilename[0] >= 'a') && (lpFilename[0] <= 'z'))) &&
              (lpFilename[1] == ':') && (lpFilename[2] == '\\'))
    {
        // Start with \??\ ...
        InitStringConstant( (void*) &ConstString, "\\??\\");
        RtlAppendStringToString( OutString, &ConstString);

        // Append the filename
        RtlInitAnsiString((void*)&InString, lpFilename);
        RtlAppendStringToString(OutString, &InString);

        // If the drive letter is lowercase, fix it
        if ((OutString->Length >= 4) && (lpFixedFilename[3] >= 'a'))
            lpFixedFilename[3] -= 'a' - 'A';
    }
    // Case .\DIR\FILENAME.EXT
    else if ((Length >= 2) &&
        (RtlCompareMemory(lpFilename, ".\\", 2) == 2))
    {
        // Initialize the output string with '\??\D:\'
        InitStringConstant(&ConstString, "\\??\\D:\\");
        RtlAppendStringToString(OutString, &ConstString);

        // Append the filename (ditch the .\)
        AdjustStringForward(&InString, 2);
        RtlAppendStringToString(OutString, &InString);
    }
    // Case \DIR\FILENAME.EXT
    else if ((Length >= 1) &&
        (RtlCompareMemory(lpFilename, "\\", 1) == 1))
    {
        // Initialize the output string with '\??\D:\'
        InitStringConstant( (void*) &ConstString, "\\??\\D:\\");
        RtlAppendStringToString(OutString, &ConstString);

        // Append the filename (ditch the initial \)
        AdjustStringForward(&InString, 1);
        RtlAppendStringToString(OutString, &InString);
    }
    // Case DIR\FILENAME.EXT (-> \??\D:\DIR\FILENAME.EXT)
    else
    {
        // Initialize the output string with '\??\D:\'
        InitStringConstant(&ConstString, "\\??\\D:\\");
        RtlAppendStringToString(OutString, &ConstString);

        // Append the filename
        RtlAppendStringToString(OutString, &InString);
    }

    // Add the final zero
    OutString->Buffer[OutString->Length] = 0;
}

// ******************************************************************
// * CreateFile
// ******************************************************************
// *
// * Creates or opens a file.  More or less the same as the Win32 
// * function CreateFileA.
// *
// ******************************************************************
HANDLE CreateFile
(
    PCHAR                   lpFilename, 
    u32                     dwDesiredAccess, 
    u32                     dwShareMode,
    SSecurity_Attributes   *lpSecurityAttributes,
    u32                     dwCreationDisposition,
    u32                     dwFlagsAndAttributes,
    HANDLE                  hTemplateFile
)
{
    char                FixedFilename[MAX_PATH];
    ANSI_STRING         Filename;
    OBJECT_ATTRIBUTES   Attributes;
    IO_STATUS_BLOCK     IoStatusBlock;
    NTSTATUS            Status;
    HANDLE              FileHandle=0;
    DWORD               Flags;

	// Fix the given filename and convert into an ANSI_STRING
    Win32FixPath(&Filename, FixedFilename, lpFilename, MAX_PATH);         

    // Initialize the object attributes.
    // Adding FILE_FLAG_POSIX_SEMANTICS removes OBJ_CASE_INSENSITIVE, but I
    // have no idea if the XBOX kernel supports case-sensitive filenames.
    InitializeObjectAttributes(
        &Attributes,
        //lpFilename,
        &Filename,
        (dwFlagsAndAttributes & FILE_FLAG_POSIX_SEMANTICS) ? 0 :
            OBJ_CASE_INSENSITIVE,
        NULL);

    // Convert dwCreationDisposition flags
    switch( dwCreationDisposition )
    {
    case    CREATE_NEW:
        dwCreationDisposition = FILE_CREATE;
        break;
    case    CREATE_ALWAYS:
        dwCreationDisposition = FILE_OVERWRITE_IF;
        break;
    case    OPEN_EXISTING:
        dwCreationDisposition = FILE_OPEN;
        break;
    case    OPEN_ALWAYS:
        dwCreationDisposition = FILE_OPEN_IF;
        break;
    // This one is special in Win32.  CreateFile errors if write access is
    // not requested.
    case    TRUNCATE_EXISTING:
        dwCreationDisposition = FILE_OVERWRITE;
        if (!(dwDesiredAccess & GENERIC_WRITE))
        {
            SetLastError(ERROR_INVALID_PARAMETER);
            return INVALID_HANDLE_VALUE;
        }
        break;
    // Win32 errors out immediately if it doesn't recognize the disposition
    default:
        SetLastError(ERROR_INVALID_PARAMETER);
        return INVALID_HANDLE_VALUE;
    }

    // Now we will convert flags for CreateFile into flags for NtCreateFile
    Flags = 0;

    // FILE_FLAG_BACKUP_SEMANTICS just allows opening directories on XBOX
    if (!(dwFlagsAndAttributes & FILE_FLAG_BACKUP_SEMANTICS))
        Flags |= FILE_NON_DIRECTORY_FILE;

    // If we're going to use blocking mode, we need to add this flag
    if (!(dwFlagsAndAttributes & FILE_FLAG_OVERLAPPED))
        Flags |= FILE_SYNCHRONOUS_IO_NONALERT;

    // Mimic Win32 by automatically adding DELETE access with this flag
    if (dwFlagsAndAttributes & FILE_FLAG_DELETE_ON_CLOSE)
    {
        dwDesiredAccess |= DELETE;
        Flags |= FILE_DELETE_ON_CLOSE;
    }

    // The rest are simple translations

    if (dwFlagsAndAttributes & FILE_FLAG_WRITE_THROUGH)
        Flags |= FILE_WRITE_THROUGH;

    if (dwFlagsAndAttributes & FILE_FLAG_NO_BUFFERING)
        Flags |= FILE_NO_INTERMEDIATE_BUFFERING;

    if (dwFlagsAndAttributes & FILE_FLAG_RANDOM_ACCESS)
        Flags |= FILE_RANDOM_ACCESS;

    if (dwFlagsAndAttributes & FILE_FLAG_SEQUENTIAL_SCAN)
        Flags |= FILE_SEQUENTIAL_ONLY;

    // Eliminate flags from dwFlagsAndAttributes, leaving only attributes
    dwFlagsAndAttributes &= (0xFFFF & ~FILE_ATTRIBUTE_DIRECTORY);

    Status = NtCreateFile(
        (void**) &FileHandle,
        dwDesiredAccess,
        &Attributes,
        &IoStatusBlock,
        NULL,
        dwFlagsAndAttributes,
        dwShareMode,
        dwCreationDisposition,
        Flags);

    LastErrorCode = Status;
    // On error, set the error code and exit
    if( Status!=0)
    {
        SetLastError( RtlNtStatusToDosError(Status) );
        return INVALID_HANDLE_VALUE;
    }


    // In CREATE_ALWAYS and OPEN_ALWAYS mode, if the file opened was
    // overwritten (we know from Information), an error code is set even
    // though the function succeeds.  This is so the application can know
    // the difference.
    if (((dwCreationDisposition == (u32) FILE_OVERWRITE_IF) && (IoStatusBlock.Information == (u32*) FILE_OVERWRITTEN)) ||
        ((dwCreationDisposition == (u32) FILE_OPEN_IF) && (IoStatusBlock.Information == (u32*) FILE_OPENED)))
        SetLastError((u32)ERROR_ALREADY_EXISTS);
    // If not an error and not the case above, clear the error
    else
        SetLastError(NO_ERROR);

    return FileHandle;
}

// ******************************************************************
// * ReadFile
// ******************************************************************
// *
// * Read data from a data file or device
// * 
// * in:		hFile = file handle
// *			lpBuffer = Destination buffer for file data
// *			nNumberOfBytesToRead = read "n" bytes
// *			lpNumberOfBytesRead  = pointer to a u32 for bytes read.
// *			lpOverlapped         = NULL unless overlap needed
// * out:       true or false based of errors
// *
// ******************************************************************
int ReadFile
(
    HANDLE       hFile,                 // file handle
    PVOID        lpBuffer,              // Dest buffer to put file
    u32          nNumberOfBytesToRead,  // read "n" bytes
    u32*         lpNumberOfBytesRead,   // pointer to a place to store bytes read
    LPOVERLAPPED lpOverlapped           // NULL unless overlap
)
{
    LARGE_INTEGER   Offset;
    IO_STATUS_BLOCK IoStatusBlock;
    NTSTATUS        Status;

    if (lpNumberOfBytesRead)
        *lpNumberOfBytesRead = 0;

    if (lpOverlapped)
    {
        Offset.LowPart = lpOverlapped->Offset;
        Offset.HighPart = lpOverlapped->OffsetHigh;
        lpOverlapped->Internal = STATUS_PENDING;

        Status = NtReadFile(
            (void*) hFile,
            (void*) lpOverlapped->hEvent,
            NULL,
            NULL,
            (void*) (PIO_STATUS_BLOCK)lpOverlapped,
            (void*) lpBuffer,
            nNumberOfBytesToRead,
            &Offset);

        if ((!NT_SUCCESS(Status))||(Status == STATUS_PENDING))
        {
            SetLastError(RtlNtStatusToDosError(Status));
            return FALSE;
        }

        if (lpNumberOfBytesRead)
            *lpNumberOfBytesRead = lpOverlapped->InternalHigh;

        SetLastError(NO_ERROR);
        return TRUE;
    }

    Status = NtReadFile(
        (void*) hFile,
        NULL,
        NULL,
        NULL,
        (void*) &IoStatusBlock,
        (void*) lpBuffer,
        nNumberOfBytesToRead,
        NULL);

    if (Status == STATUS_PENDING)
    {
        Status = NtWaitForSingleObject(
            (void*) hFile,
                    FALSE,
            (void*) NULL);
    }

    if (NT_SUCCESS(Status))
    {
        if (lpNumberOfBytesRead)
            *lpNumberOfBytesRead = (u32)IoStatusBlock.Information;
        SetLastError(NO_ERROR);
        return TRUE;
    }

    SetLastError(RtlNtStatusToDosError(Status));
    return FALSE;
}

// ******************************************************************
// * CloseHandle
// ******************************************************************
// *
// * Close an open handle.  This is a simple wrapper around NtClose.
// *
// * in:		Handle to open file
// * out:       true or false if file closed.
// *
// ******************************************************************
int CloseHandle(HANDLE Handle)
{
    NTSTATUS    Status;

    Status = NtClose( (void*) Handle);

    if (!NT_SUCCESS(Status))
    {
        SetLastError(RtlNtStatusToDosError(Status));
        return FALSE;
    }

    SetLastError(NO_ERROR);
    return TRUE;
}




// ******************************************************************
// * GetFileSizeEx
// ******************************************************************
// *
// * Get the size of an "open" file
// *
// * In:             hfile       = handle to open file
// *                 lpFileSize  = pointer to LARGE_INTEGER to store size
// * Out:            int         = true for okay
// *                             = false for error
// *
// ******************************************************************
int GetFileSizeEx(  HANDLE hFile, PLARGE_INTEGER lpFileSize)
{
    NTSTATUS            Status;
    IO_STATUS_BLOCK     IoStatusBlock;
    FILE_NETWORK_OPEN_INFORMATION   OpenInfo;

    // We use FileNetworkOpenInformation from NtQueryInformationFile to get
    // the file size.  This trick I got from Windows XP's implementation,
    // which seems to work on XBOX.
    if (!NT_SUCCESS(Status = NtQueryInformationFile(hFile, &IoStatusBlock,
        &OpenInfo, sizeof(OpenInfo), FileNetworkOpenInformation)))
    {
        SetLastError(RtlNtStatusToDosError(Status));
        return FALSE;
    }

    // Copy the file size to the caller's variable
    *lpFileSize = OpenInfo.EndOfFile;

    // This is *absolutely important* to correct operation of GetFileSize!
    SetLastError(NO_ERROR);
    return TRUE;
}




// ******************************************************************
// * SetFilePointerEx
// ******************************************************************
// *
// * Move file pointer around
// *
// * NOTE:        Until I do some 64bit functions, OR we get to use __int64
// *              we are restricted to 32bit long files. (4 gig?)
// *
// ******************************************************************
int SetFilePointerEx(   HANDLE hFile,
                        LARGE_INTEGER liDistanceToMove,
                        PLARGE_INTEGER lpNewFilePointer,
                        DWORD dwMoveMethod)
{
    FILE_POSITION_INFORMATION       PositionInfo;
    LARGE_INTEGER                   TargetPointer;
    IO_STATUS_BLOCK                 IoStatusBlock;
    NTSTATUS                        Status;

    TargetPointer.HighPart = liDistanceToMove.HighPart;
    // Calculate the target pointer
    switch (dwMoveMethod)
    {
        // From the beginning of the file
        case FILE_BEGIN:            TargetPointer.LowPart = liDistanceToMove.LowPart;
                                    break;

        // From the current position
        case FILE_CURRENT:          Status = NtQueryInformationFile( hFile, &IoStatusBlock, &PositionInfo, sizeof(PositionInfo), FilePositionInformation);
                                    if(Status!=NO_ERROR) goto Error;

                                    // Calculate new file pointer
                                    TargetPointer.LowPart = PositionInfo.CurrentByteOffset.LowPart + liDistanceToMove.LowPart;
                                    //*((PLARGE_INTEGER) &TargetPointer.LowPart) = AddU64((PLARGE_INTEGER) &(PositionInfo.CurrentByteOffset.LowPart) , (PLARGE_INTEGER) &(liDistanceToMove.LowPart));
                                    break;

        // From the end of the file
        case FILE_END:              if (!GetFileSizeEx(hFile, &TargetPointer))
                                    goto ErrorWin32;

                                    // Calculate new file pointer
                                    TargetPointer.LowPart -= liDistanceToMove.LowPart;
                                    //TargetPointer.QuadPart -= liDistanceToMove.QuadPart;
                                    break;

        default:
                SetLastError(ERROR_INVALID_PARAMETER);
                goto ErrorWin32;
    }

    // Don't allow a negative seek
    //if (TargetPointer.QuadPart < 0)
    if ( (TargetPointer.LowPart&0x80000000) != 0)
    {
        SetLastError(ERROR_NEGATIVE_SEEK);
        goto ErrorWin32;
    }

    // Fill in the new position information
    PositionInfo.CurrentByteOffset.HighPart = TargetPointer.HighPart;
    PositionInfo.CurrentByteOffset.LowPart= TargetPointer.LowPart;

    // Set the new position
    Status = NtSetInformationFile( (void*) hFile, &IoStatusBlock,&PositionInfo, sizeof(PositionInfo), FilePositionInformation );
    if(Status!=NO_ERROR) goto Error;

    // Return the new pointer
    if (lpNewFilePointer) {
        lpNewFilePointer->HighPart = TargetPointer.HighPart;
        lpNewFilePointer->LowPart = TargetPointer.LowPart;
    }
    return TRUE;

Error:
    SetLastError( RtlNtStatusToDosError(Status) );
ErrorWin32:
    return FALSE;
}




// ******************************************************************
// * WriteFile
// ******************************************************************
// *
// * Write data to a data file or device
// *
// * in:		hFile = file handle
// *			lpBuffer = Source buffer for file data
// *			nNumberOfBytesToWrite= write "n" bytes
// *			lpNumberOfBytesWritten = pointer to a u32 for bytes written
// *			lpOverlapped = NULL unless overlap needed
// * out:       true or false based of errors
// *
// ******************************************************************
int WriteFile(  HANDLE          hFile, 
                PVOID           lpBuffer,
                u32             nNumberOfBytesToWrite,
                u32*            lpNumberOfBytesWritten,
                LPOVERLAPPED    lpOverlapped)
{
    LARGE_INTEGER   Offset;
    IO_STATUS_BLOCK IoStatusBlock;
    NTSTATUS        Status;

    if(lpNumberOfBytesWritten){
        *lpNumberOfBytesWritten = 0;
    }

    if (lpOverlapped)
    {
        Offset.LowPart = lpOverlapped->Offset;
        Offset.HighPart = lpOverlapped->OffsetHigh;
        lpOverlapped->Internal = STATUS_PENDING;

        Status = NtWriteFile(
            (void*)hFile,
            (void*)lpOverlapped->hEvent,
            NULL,
            NULL,
            (PIO_STATUS_BLOCK)lpOverlapped,
            lpBuffer,
            nNumberOfBytesToWrite,
            &Offset);

        if ((!NT_SUCCESS(Status))||(Status == STATUS_PENDING))
        {
            SetLastError(RtlNtStatusToDosError(Status));
            return FALSE;
        }

        if (lpNumberOfBytesWritten)
            *lpNumberOfBytesWritten = lpOverlapped->InternalHigh;

        SetLastError(NO_ERROR);
        return TRUE;
    }

    Status = NtWriteFile(   (void*)hFile,
                            NULL,
                            NULL,
                            NULL,
                            &IoStatusBlock,
                            lpBuffer,
                            nNumberOfBytesToWrite,
                            NULL);

    if (Status == STATUS_PENDING)
    {
        Status = NtWaitForSingleObject(
            (void*) hFile,
            FALSE,
            NULL);
    }

    if (NT_SUCCESS(Status))
    {
        if (lpNumberOfBytesWritten){
            *lpNumberOfBytesWritten = (u32)IoStatusBlock.Information;
        }
        SetLastError(NO_ERROR);
        return TRUE;
    }

    SetLastError(RtlNtStatusToDosError(Status));
    return FALSE;
}



/*
// ******************************************************************
// * AddU64
// ******************************************************************
// *
// * U64 support - will move to math later
// *
// ******************************************************************
LARGE_INTEGER   AddU64( PLARGE_INTEGER  A,PLARGE_INTEGER  B )
{
    u32 t,carry;
    LARGE_INTEGER   answer;

    t = (A->LowPart&0xffff)+(B->LowPart&0xffff);                                // bits 0-15
    answer.LowPart = t&0xffff;
    carry = (t>>16)&0xffff;

    t = ((A->LowPart>>16)&0xffff)+((B->LowPart>>16)&0xffff)+carry;  // bits 16-31
    answer.LowPart |= ((t&0xffff)<<16);
    carry = (t>>16)&0xffff;
    
    t = ((A->HighPart)&0xffff)+((B->HighPart)&0xffff)+carry;        // bits 32-47
    answer.HighPart |= ((t&0xffff)<<16);
    carry = (t>>16)&0xffff;

    t = ((A->HighPart>>16)&0xffff)+((B->HighPart>>16)&0xffff)+carry;    // bits 48-63
    answer.HighPart |= ((t&0xffff)<<16);
    //carry = (t>>16)&0xffff;
}*/














