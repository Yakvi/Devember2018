/* =======================================================================
   $File: Devember 2018 - win32 layer $
   $Date: 01.12.2018 $
   $Revision: $
   $Creator: Ivan Yakymchak $
   $Notice: (C) Copyright 2018 by Ivan Yakymchak. All Rights Reserved. $
   ======================================================================= */

#include <windows.h>
#include "devember_platform.cpp"

LRESULT CALLBACK
MainWindowProcedure(HWND Window,
                    UINT Message,
                    WPARAM wParam,
                    LPARAM lParam)
{
    switch (Message)
    {
    case WM_PAINT:
    {
    }
    break;
    }
}

int CALLBACK
WinMain(HINSTANCE Instance,
        HINSTANCE PrevInstance,
        LPSTR CommandLine,
        int CmdShow)
{
    WNDCLASS WindowClass = {};
    WindowClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
    WindowClass.hInstance = Instance;
    WindowClass.lpfnWndProc = MainWindowProcedure;

#if 0
    MessageBoxA(0, "Hello world!", "Hello", MB_OK|MB_ICONINFORMATION);
    MessageBoxA(0, "This is another message box!", "Hello", MB_OK|MB_ICONINFORMATION);
    MessageBoxA(0, "This is not an error.", "Error", MB_OK|MB_ICONERROR);
#endif

    return (0);
}