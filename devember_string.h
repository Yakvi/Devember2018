#if !defined(DEVEMBER_STRING_H)
/* =======================================================================
   $File: Devember 2018 - String $
   $Date: 06/12/2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

#define MAX_CHUNK_LENGTH 8
#define END_OF_CURRENT_FILE(State) State->CurrentFile.DataSize

struct string_chunk
{
    u32 CurrentChunkSize;
    char Buffer[MAX_CHUNK_LENGTH];
    string_chunk *Next;
};

struct string
{
    u32 Length;
    string_chunk *FirstChunk;
    string_chunk *LastChunk;
};

#define DEVEMBER_STRING_H
#endif