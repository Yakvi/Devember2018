#if !defined(WIN32_DEVEMBER_H)
/* =======================================================================
   $File: Devember 2018 - Win32 layer header $
   $Date: 05/12/2018 $
   $Creator: Ivan Yakymchak $
   ======================================================================= */

struct win32_program_code
{
    HMODULE ProgramDLL;
    main_loop *MainLoop;
    b32 IsValid;
};

#define WIN32_DEVEMBER_H
#endif
