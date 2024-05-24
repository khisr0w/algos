/*  +======| File Info |===============================================================+
    |                                                                                  |
    |     Subdirectory:  /src                                                          |
    |    Creation date:  3/29/2024 5:44:11 PM                                          |
    |    Last Modified:                                                                |
    |                                                                                  |
    +======================================| Copyright © Sayed Abid Hashimi |==========+  */

#include <stdint.h>
typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t i32;
typedef int64_t i64;
typedef float f32;
typedef double f64;
typedef uintptr_t uintptr;
typedef int8_t bool;
typedef size_t usize;
#define true 1
#define false 0
#define internal static
#define local_persist static
#define global_var static
#define ArrayLength(Array) (sizeof(Array)/sizeof(Array[0]))
#define Assert(Expr, ErrorStr) if(!(Expr)) {fprintf(stderr, "ASSERTION ERROR (%s:%d): " ErrorStr "\n", __FILE__, __LINE__); *(i32 *)0 = 0; }
