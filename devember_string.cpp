/* =======================================================================
   $File: Devember 2018 - String $
   $Date: 06/12/2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

inline string_chunk *
GetNewChunk(program_state *State, string_chunk *Prev)
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

    if (Prev)
    {
        Prev->Next = NewChunk;
    }

    return (NewChunk);
}

inline string
GetString(program_state *State, char *Input)
{
    string Result = {};

    u32 StringLength = 0;
    u32 CurrentChunkSize = 0;
    string_chunk *Chunk = Result.FirstChunk = GetNewChunk(State, 0);

    for (char *At = Input;
         *At;
         ++At, ++StringLength)
    {
        Chunk->Buffer[CurrentChunkSize++] = *At;

        if (CurrentChunkSize == STRING_CHUNK_SIZE)
        {
            CurrentChunkSize = 0;
            Chunk = GetNewChunk(State, Chunk);
        }
    }
    Chunk->Buffer[CurrentChunkSize] = 0;

    Result.Length = StringLength;

    return (Result);
}

internal b32
Overwrite(program_state *State, string Source, char *Dest, u32 Cursor, u32 *DataSize)
{
    b32 StringEnded = false;
    u32 Typed = 0;

    for (string_chunk *Chunk = Source.FirstChunk;
         Chunk;)
    {
        if (!StringEnded)
        {
            for (u32 CurrentChar = 0;
                 CurrentChar < STRING_CHUNK_SIZE;
                 ++CurrentChar)
            {
                if (Chunk->Buffer[CurrentChar] &&
                    Typed++ < Source.Length)
                {
                    Dest[Cursor++] = Chunk->Buffer[CurrentChar];

                    if (Cursor > *DataSize)
                    {
                        *DataSize = *DataSize + 1;
                    }
                }
                else
                {
                    // NOTE(ivan): We reached end of the string
                    StringEnded = true;
                    break;
                }
            }
        }

        string_chunk *Temp = State->FirstFreeChunk;
        State->FirstFreeChunk = Chunk;
        Chunk = Chunk->Next;
        State->FirstFreeChunk->Next = Temp;
    }

    return (StringEnded);
}

internal void
Overwrite(program_state *State, char *Input, u32 DesiredPos)
{
    open_file *File = &State->CurrentFile;

    File->Cursor = DesiredPos;
    char *Dest = File->Data;
    string String = GetString(State, Input);

    Overwrite(State, String, File->Data, File->Cursor, &File->DataSize);
}

internal void
Insert(program_state *State, char *Input, u32 DesiredPos)
{
    open_file *File = &State->CurrentFile;
    
    char *Dest = File->Data;
    
    string ShiftedText = GetString(State, File->Data + DesiredPos);
    string InsertedText = GetString(State, Input);

    u32 NewCursor = DesiredPos + InsertedText.Length;

    Overwrite(State, ShiftedText, File->Data, NewCursor, &File->DataSize);
    Overwrite(State, InsertedText, File->Data, DesiredPos, &File->DataSize);
}