#if !defined(DEVEMBER_PLATFORM_H)
/* =======================================================================
   $File: Devember 2018 - platform layer $
   $Date: 01.12.2018 $
   $Revision: $
   $Creator: Ivan Yakymchak $
   $Notice: (C) Copyright 2018 by Ivan Yakymchak. All Rights Reserved. $
   ======================================================================= */

//
// NOTE: Types
//
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <float.h>

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef s32 b32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uintptr_t uintptr;
typedef size_t memory_index;
typedef float f32;
typedef double f64;

#define Real32Maximum FLT_MAX

#if !defined(internal)
#define internal static
#endif
#define local_persist static
#define global_variable static

#define Pi32 3.14159265359f
#define Tau32 6.28318530717958647692f

#if DEVEMBER_DEV
#define Assert(Expression) \
    if (!(Expression))     \
    {                      \
        *(int *)0 = 0;     \
    }
#else
#define Assert(Expression)
#endif

#define DEVEMBER_PLATFORM_H
#endif