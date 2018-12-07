#if !defined(DEVEMBER_H)
/* =======================================================================
$File: Devember 2018 - Main Loop File Header$
$Date: 05/12/2018 $
$Creator: Ivan Yakymchak $
======================================================================= */
#include "devember_platform.h"

#define MAX_BUFFER_SIZE Megabytes(1)

struct memory_arena
{
    memory_index Size;
    u8 *Base;
    memory_index Used;

    u32 TempCount;
};

inline void
InitializeArena(memory_arena *Arena, memory_index Size, void *Base)
{
    Arena->Size = Size;
    Arena->Base = (u8 *)Base;
    Arena->Used = 0;
    Arena->TempCount = 0;
}

inline memory_index
GetAlignmentOffset(memory_arena *Arena, memory_index Alignment = 4)
{
    memory_index AlignmentOffset = 0;

    memory_index ResultPointer = (memory_index)Arena->Base + Arena->Used;
    memory_index AlignmentMask = Alignment - 1;
    if (ResultPointer & AlignmentMask)
    {
        AlignmentOffset = Alignment - (ResultPointer & AlignmentMask);
    }

    return (AlignmentOffset);
}

inline memory_index
GetArenaSizeRemaining(memory_arena *Arena, memory_index Alignment = 4)
{
    memory_index Result = Arena->Size - (Arena->Used - GetAlignmentOffset(Arena, Alignment));

    return (Result);
}

#define PushStruct(Arena, type, ...) (type *)PushSize_(Arena, sizeof(type), ##__VA_ARGS__)
#define PushArray(Arena, Count, type, ...) (type *)PushSize_(Arena, (Count) * sizeof(type), ##__VA_ARGS__)
#define PushSize(Arena, Size, ...) PushSize_(Arena, Size, ##__VA_ARGS__)
#define PushCopy(Arena, Size, Source, ...) Copy(Size, Source, PushSize_(Arena, Size, ##__VA_ARGS__))
inline void *
PushSize_(memory_arena *Arena, memory_index SizeInit, memory_index Alignment = 4)
{
    memory_index Size = SizeInit;
    // NOTE(ivan): Take a look where we would be
    memory_index AlignmentOffset = GetAlignmentOffset(Arena, Alignment);
    Size += AlignmentOffset;

    // NOTE(ivan): Ensure we can fit the amount requested in memory
    Assert((Arena->Used + Size) <= Arena->Size);

    void *Result = Arena->Base + Arena->Used + AlignmentOffset;
    Arena->Used += Size;

    Assert(Size >= SizeInit);

    return (Result);
}

inline void *
Copy(memory_index Size, void *SourceInit, void *DestInit)
{
    u8 *Source = (u8 *)SourceInit;
    u8 *Dest = (u8 *)DestInit;

    while (Size--)
    {
        *Dest++ = *Source++;
    }

    return (DestInit);
}

struct program_state;

#include "devember_string.h"

struct program_state
{
    char *CurrentFileName;
    open_file CurrentFile;
    memory_arena Arena;

    string *FirstFreeString;
    string_chunk *FirstFreeChunk;
};

#define DEVEMBER_H
#endif
