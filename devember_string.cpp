/* =======================================================================
   $File: Devember 2018 - String $
   $Date: 06/12/2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

internal string_chunk *
GetNewChunk(program_state *State, string_chunk *Prev)
{
    string_chunk *NewChunk;
    if (State->FirstFreeChunk)
    {
        NewChunk = State->FirstFreeChunk;
        State->FirstFreeChunk = NewChunk->Next;
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

internal string *
GetString(program_state *State, char *Input)
{
    string *Result = PushStruct(&State->Arena, string);

    u32 StringLength = 0;
    u32 CurrentChunkSize = 0;
    string_chunk *Chunk = Result->FirstChunk = GetNewChunk(State, 0);

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
    Chunk->Buffer[CurrentChunkSize] = '\0';
    
    Result->Length = StringLength;

    return (Result);
}

internal b32
Overwrite(program_state *State, string *String, u32 DesiredPos = MAX_BUFFER_SIZE)
{
    b32 StringEnded = false;

    if(DesiredPos >= MAX_BUFFER_SIZE)
    {
        DesiredPos = END_OF_CURRENT_FILE(State);
    }

    open_file *File = &State->CurrentFile;

    File->Cursor = DesiredPos;
    char *Dest = (char *)File->Data + File->Cursor;
    for (string_chunk *Chunk = String->FirstChunk;
         Chunk;)
    {
        if(!StringEnded)
        {
            for (u32 CurrentChar = 0;
                CurrentChar < STRING_CHUNK_SIZE;
                ++CurrentChar)
            {
                if (Chunk->Buffer[CurrentChar])
                {
                    *Dest++ = Chunk->Buffer[CurrentChar];
                    ++File->DataSize;
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
