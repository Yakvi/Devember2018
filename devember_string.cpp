/* =======================================================================
   $File: Devember 2018 - String $
   $Date: 06/12/2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

inline string_chunk *
GetNewChunk(program_state *State, string *String)
{
    string_chunk *NewChunk;
    if (State->FirstFreeChunk)
    {
        NewChunk = State->FirstFreeChunk;
        State->FirstFreeChunk = NewChunk->Next;
        NewChunk->Next = 0;
    }
    else
    {
        NewChunk = PushStruct(&State->Arena, string_chunk);
    }

    NewChunk->CurrentChunkSize = 0;

    if(String->LastChunk)
    {
        String->LastChunk->Next = NewChunk;
    }
    String->LastChunk = NewChunk;

    return (NewChunk);
}

inline string_chunk *
GetNextFreeChunk(program_state *State, string *String)
{
    string_chunk *Result = String->LastChunk;
    if (Result->CurrentChunkSize >= MAX_CHUNK_LENGTH)
    {
       Result = GetNewChunk(State, String);
    }

    return (Result);
}

inline u32
ReadChunk(string_chunk *Chunk, char *Dest)
{
    Assert(Chunk->CurrentChunkSize <= MAX_CHUNK_LENGTH);
    Assert(Chunk->CurrentChunkSize > 0);
    u32 Typed = 0;
    char *At = Chunk->Buffer;
    while (*At && (Typed++ <= MAX_CHUNK_LENGTH))
    {
        *Dest++ = *At++;
    }

    return Typed;
}

inline void
CloseString(program_state *State, string *String)
{
    // Add null terminator
    string_chunk *Chunk = GetNextFreeChunk(State, String);
    Chunk->Buffer[Chunk->CurrentChunkSize++] = 0;
}

inline string
GetString(program_state *State)
{
    string Result = {};

    Result.FirstChunk = Result.LastChunk = GetNewChunk(State, &Result);
    Result.Length = 0;

    return (Result);
}

internal void
Write(program_state *State, char *Source, string *Dest)
{
    string_chunk *Chunk = GetNextFreeChunk(State, Dest);
    Chunk->Buffer[Chunk->CurrentChunkSize++] = *Source;
    ++Dest->Length;
}

inline string
ToString(program_state *State, char *At)
{
    string String = GetString(State);

    while (*At)
    {
        Write(State, At++, &String);
    }
    CloseString(State, &String);

    return (String);
}

inline u32
ToChar(program_state *State, string *Source, char *Dest, u32 MaxLength = UINT32_MAX)
{
    u32 Typed = 0;
    for (;;)
    {
        string_chunk *Chunk = Source->FirstChunk;
        if (Chunk && (Typed < MaxLength))
        {
            Typed += ReadChunk(Chunk, Dest + Typed);

            Source->FirstChunk = Chunk->Next;
            Chunk->Next = State->FirstFreeChunk;
            State->FirstFreeChunk = Chunk;
        }
        else
        {
            break;
        }
    }

    return (Typed);
}

internal void
OverwriteToFile(program_state *State, char *Input, u32 DesiredPos)
{
    open_file *File = &State->CurrentFile;
    if(DesiredPos > File->DataSize)
    {
        DesiredPos = File->DataSize;
    }

    File->Cursor = DesiredPos;
    char *Dest = File->Data;
    string String = ToString(State, Input);

    u32 Typed = ToChar(State, &String, File->Data + File->Cursor);
    u32 NewCursor = File->Cursor + Typed;
    if (NewCursor > File->DataSize)
    {
        File->DataSize = NewCursor;
    }
}

internal void
InsertToFile(program_state *State, char *Input, u32 DesiredPos)
{
    open_file *File = &State->CurrentFile;
    if(DesiredPos > File->DataSize)
    {
        File->Cursor = File->DataSize;
    }

    char *Dest = File->Data;

    string ShiftedText = ToString(State, File->Data + File->Cursor);
    string InsertedText = ToString(State, Input);

    u32 Shift = File->Cursor + InsertedText.Length;

    ToChar(State, &ShiftedText, File->Data + Shift);
    u32 Typed = ToChar(State, &InsertedText, File->Data + File->Cursor);
    u32 NewCursor = File->Cursor + Typed;
    if (NewCursor > File->DataSize)
    {
        File->DataSize = NewCursor;
    }
}
