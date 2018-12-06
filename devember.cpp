/* =======================================================================
   $File: Devember 2018 - Main Loop File $
   $Date: 05/12/2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

#include "devember.h"

#include "devember_string.cpp"

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

    State->CurrentFile = Platform.ReadEntireFile(State->CurrentFileName); // TODO: This will eventually create problems. We must actually use buffers specifically for each file
    Assert(State->CurrentFile.DataSize <= MAX_BUFFER_SIZE);

    string *String = GetString(State, "This is a test.\n");
    Overwrite(State, String);
    String = GetString(State, "Ciao Chiara.\n");
    Overwrite(State, String);
    // TODO: Insert (and move the text)
    // FormatFile(&File); TODO: r/RestOfTheDamnRoutine
    Platform.SaveToFile(&State->CurrentFile, State->CurrentFileName);
}