#if !defined(DEVEMBER_STRING_H)
/* =======================================================================
   $File: Devember 2018 - String $
   $Date: 06/12/2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

#define STRING_CHUNK_SIZE 8
#define END_OF_CURRENT_FILE(State) State->CurrentFile.DataSize

struct string_chunk
{
    char Buffer[STRING_CHUNK_SIZE];
    string_chunk *Next;
};

struct string
{
    u32 Length;
    string_chunk *FirstChunk;
};

#define DEVEMBER_STRING_H
#endif