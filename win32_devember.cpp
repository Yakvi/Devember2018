/* =======================================================================
   $File: Devember 2018 - win32 layer $
   $Date: 01.12.2018 $
   $Revision: $
   $Creator: Ivan Yakymchak $
   $Notice: (C) Copyright 2018 by Ivan Yakymchak. All Rights Reserved. $
   ======================================================================= */

#include <windows.h>
#include "devember_platform.cpp"

int CALLBACK
WinMain(HINSTANCE Instance,
        HINSTANCE PrevInstance,
        LPSTR CommandLine,
        int CmdShow)
{
    WNDCLASS WindowClass = {};

    MessageBoxA(0, "Hello world!", "Hello", MB_OK|MB_ICONINFORMATION);
    MessageBoxA(0, "This is another message box!", "Hello", MB_OK|MB_ICONINFORMATION);
    MessageBoxA(0, "This is not an error.", "Error", MB_OK|MB_ICONERROR);

    return (0);
}