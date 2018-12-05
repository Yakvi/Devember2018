/* =======================================================================
   $File: Devember 2018 - Main Loop File $
   $Date: 05/12/2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

#include "devember_platform.h"
#include <windows.h>

extern "C" MAIN_LOOP(MainLoop)
{
    platform_api Platform = Memory->PlatformAPI;

    if (!Memory->IsLoaded)
    {

        Memory->IsLoaded = true;
    }
    open_file File = Platform.ReadEntireFile(Memory->TEMPFileName);
    OutputDebugStringA((char *)File.Data);

    // FormatFile(&File); TODO: r/RestOfTheDamnRoutine
    //Win32WriteFile(&File, FileName);
}