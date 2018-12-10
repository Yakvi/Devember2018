/* =======================================================================
   $File: Devember 2018 - Main Loop File $
   $Date: 05/12/2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

#include "devember.h"

#include "devember_string.cpp"

inline b32
IsWhitespace(char *At)
{
    b32 Result = ((At[0] == ' ') ||
                  (At[0] == '\n') ||
                  (At[0] == '\t'));

    return (Result);
}

internal string
ParseFile(program_state *State, open_file *File)
{
    string Output = GetString(State);
    b32 Parsing = true;
    char *At = File->Data;
    while (Parsing)
    {
        if (At[0] == '\0')
        {
            Parsing = false;
        }

        if (At[0] == '{')
        {
        }
        if (At[0] == '}')
        {
            while(IsWhitespace(At))
            {
                ++At;
            }
        }

        //Overwrite(State, " ")
        ++At;

    }

    return(Output);
}

extern "C" MAIN_LOOP(MainLoop)
{
    platform_api Platform = Memory->PlatformAPI;

    Assert(sizeof(program_state) <= Memory->MemorySize);
    program_state *State = (program_state *)Memory->Memory;
    if (!Memory->IsLoaded)
    {
        InitializeArena(&State->Arena, (memory_index)Memory->MemorySize - sizeof(program_state), (u8 *)Memory->Memory + sizeof(program_state));
        State->CurrentFileName = Memory->TEMPFileName;
        State->FirstFreeChunk = 0;

        Memory->IsLoaded = true;
    }

    // TODO(ivan): This will eventually create problems.
    //  We must actually use buffers specifically for each file to avoid going colliding inside other stuff on arena
    State->CurrentFile = Platform.ReadEntireFile(State->CurrentFileName);
    Assert(State->CurrentFile.DataSize <= MAX_BUFFER_SIZE);

    //ParseFile(State, &State->CurrentFile);
    InsertToFile(State, "/* Test12345 Another bunch of chunks", 3000);

    Platform.SaveToFile(&State->CurrentFile, State->CurrentFileName);
}