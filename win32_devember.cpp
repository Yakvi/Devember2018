/* =======================================================================
   $File: Devember 2018 - win32 layer $
   $Date: 01.12.2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

#include <windows.h>
#include <stdio.h>
#include "devember_platform.h"
#include "win32_devember.h"

internal void
Win32Error(char *A, char *B, char *C)
{
    char Buffer[512];
    _snprintf_s(Buffer, sizeof(Buffer),
                "ERROR: %s %s %s \n", A, B, C);
    OutputDebugStringA(Buffer);
}

internal PLATFORM_READ_ENTIRE_FILE(Win32ReadEntireFile)
{
    open_file Result = {};

    HANDLE FileHandle = CreateFileA(FileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if (FileHandle != INVALID_HANDLE_VALUE)
    {
        LARGE_INTEGER FileSize;
        if (GetFileSizeEx(FileHandle, &FileSize))
        {
            u32 FileSize32 = SafeTruncateUInt64(FileSize.QuadPart);
            Result.Data = VirtualAlloc(0, FileSize32, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
            if (Result.Data)
            {
                DWORD BytesRead;
                if (ReadFile(FileHandle, Result.Data, FileSize32, &BytesRead, 0) && (FileSize32 == BytesRead))
                {
                    //NOTE: File read successfully, confirm data size
                    Result.DataSize = FileSize32;
                }
                else
                {
                    Win32Error(FileName, "read failure.", "Possible expected size/bytes read mismatch.");
                    VirtualFree(Result.Data, 0, MEM_RELEASE);
                    Result.Data = 0;
                }
            }
            else
            {
                Win32Error("Memory allocation for", FileName, "failed.");
            }
        }
        else
        {
            Win32Error("Filesize fetch for", FileName, "failed.");
        }

        CloseHandle(FileHandle);
    }
    else
    {
        Win32Error("Handle creation for", FileName, "failed.");
    }

    return (Result);
}

internal PLATFORM_WRITE_ENTIRE_FILE(Win32WriteEntireFile)
{
    b32 Result = false;

    HANDLE FileHandle = CreateFileA(FileName, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0);
    if (FileHandle != INVALID_HANDLE_VALUE)
    {
        DWORD BytesWritten;
        if (WriteFile(FileHandle, File->Data, File->DataSize, &BytesWritten, 0))
        {
            Assert(BytesWritten == File->DataSize);
        }
        else
        {
            Win32Error("File writing to", FileName, "failed.");
        }

        Result = true;
        CloseHandle(FileHandle);
    }
    else
    {
        Win32Error("Handle creation for", FileName, "failed.");
    }

    return (Result);
}

internal win32_program_code
Win32GetProgramCode(char *DLLName)
{
    win32_program_code Result = {};

    Result.ProgramDLL = LoadLibraryA(DLLName);
    if (Result.ProgramDLL)
    {
        Result.MainLoop = (main_loop *)
            GetProcAddress(Result.ProgramDLL, "MainLoop");

        if (Result.MainLoop)
        {
            Result.IsValid = true;
        }
    }

    return (Result);
}

int main(int argc, char const *argv[])
{
    char *FileName = "H:/Devember2018/data/test.cpp";

    main_memory Memory = {};
    Memory.MemorySize = Megabytes(20);
    Memory.Memory = VirtualAlloc(0, (memory_index)Memory.MemorySize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

    Memory.PlatformAPI.ReadEntireFile = Win32ReadEntireFile;
    Memory.PlatformAPI.WriteEntireFile = Win32WriteEntireFile;

    Memory.TEMPFileName = FileName;

    win32_program_code Program = Win32GetProgramCode("H:/Devember2018/build/devember.dll");

    if (Program.IsValid)
    {
        Program.MainLoop(&Memory);
    }

    return (0);
}
