/*  +======| File Info |===============================================================+
    |                                                                                  |
    |     Subdirectory:  /src                                                          |
    |    Creation date:  6/1/2024 8:48:48 PM                                           |
    |    Last Modified:                                                                |
    |                                                                                  |
    +======================================| Copyright © Sayed Abid Hashimi |==========+  */

#include <stdio.h>
#include <stdint.h>

/* NOTE(Abid): To have at least 64-bit integer. We could omit `int` from it as well. */
typedef int32_t i32;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef double f64;

/* NOTE(Abid): Period = 10^12 */
struct faster_rand {
    u64 V;

    /* NOTE(Abid): Reserve bits for U8 and U16 routines. */
    i32 NumU8Reserves = 0;
    i32 NumU16Reserves = 0;
    u64 U8Reserves;
    u64 U16Reserves;

    faster_rand(u64 Seed) : V(4101842887655102017LL) {
        V ^= Seed;
        V = U64();
    }
    inline f64 F64() { return 5.42101086242752217e-20 * (f64)U64(); }
    inline u64 U64() {
        V ^= V >> 21;
        V ^= V << 35;
        V ^= V >> 4;
        return V * 2685821657736338717LL;
    }
    inline u32 U32() { return (u32)U64(); }
    inline u16 U16() {
        if(NumU16Reserves--) { return (u16)(U16Reserves >>= 16); }
        U16Reserves = U64();
        NumU16Reserves = 3;

        return (u16)U16Reserves;
    }
    inline u8 U8() {
        if(NumU8Reserves--) { return (u8)(U8Reserves >>= 8); }
        U8Reserves = U64();
        NumU8Reserves = 7;

        return (u8)U8Reserves;
    }

    inline u64 RangeU64(u64 Min, u64 Max) {
        /* NOTE(Abid): Range in [Min, Max) */

        /* TODO(Abid): Get rid of modulus in here (faster). */
        return Min + U64() % (Max-Min);
    }
};

/* NOTE(Abid): Period = 8.5x10^37 */
struct fast_rand {
    u64 V, W;

    i32 NumU8Reserves = 0;
    i32 NumU16Reserves = 0;
    u64 U8Reserves;
    u64 U16Reserves;
    fast_rand(u64 Seed) : V(4101842887655102017LL), W(1) {
        V ^= Seed;
        W = U64();
        V = U64();
    }
    inline f64 F64() { return 5.42101086242752217e-20 * (f64)U64(); }
    inline u64 U64() {
        V ^= V >> 17;
        V ^= V << 31;
        V ^= V >> 8;
        W = 4294957665U * (W & 0xffffffff) + (W >> 32);

        return V ^ W;
    }
    inline u32 U32() { return (u32)U64(); }
    inline u16 U16() {
        if(NumU16Reserves--) { return (u16)(U16Reserves >>= 16); }
        U16Reserves = U64();
        NumU16Reserves = 3;

        return (u16)U16Reserves;
    }
    inline u8 U8() {
        if(NumU8Reserves--) { return (u8)(U8Reserves >>= 8); }
        U8Reserves = U64();
        NumU8Reserves = 7;

        return (u8)U8Reserves;
    }
    inline u64 RangeU64(u64 Min, u64 Max) {
        /* NOTE(Abid): Range in [Min, Max) */

        /* TODO(Abid): Get rid of modulus in here (faster). */
        return Min + U64() % (Max-Min);
    }
};

struct rand {
    u64 U, V, W;

    i32 NumU8Reserves = 0;
    i32 NumU16Reserves = 0;
    u64 U8Reserves;
    u64 U16Reserves;
    rand(u64 Seed): V(4101842887655102017LL), W(1) {
        U = Seed ^ V; U64();
        V = U; U64();
        W = V; U64();
    }

    inline double F64() { return 5.42101086242752217e-20 * (f64)U64(); }
    inline u64 U64() {
        U = U * 2862933555777941757LL + 7046029254386353087LL;
        V ^= V >> 17;
        V ^= V << 31;
        V ^= V >> 8;
        W = 4294957665U * (W & 0xffffffff) + (W >> 32);

        u64 X = U ^ (U << 21);
        X ^= X >> 35;
        X ^= X << 4;

        return (X + V) ^ W;
    }
    inline u32 U32() { return (u32)U64(); }
    inline u16 U16() {
        if(NumU16Reserves--) { return (u16)(U16Reserves >>= 16); }
        U16Reserves = U64();
        NumU16Reserves = 3;

        return (u16)U16Reserves;
    }
    inline u8 U8() {
        if(NumU8Reserves--) { return (u8)(U8Reserves >>= 8); }
        U8Reserves = U64();
        NumU8Reserves = 7;

        return (u8)U8Reserves;
    }
    inline u64 RangeU64(u64 Min, u64 Max) {
        /* NOTE(Abid): Range in [Min, Max) */

        /* TODO(Abid): Get rid of modulus in here (faster). */
        return Min + U64() % (Max-Min);
    }
};

int main(int argc, char *args[]) {
    for(u64 Seed = 13; Seed < 500; Seed += 13) {
        faster_rand RNG(Seed);
        // printf("Seed: %lld\n", Seed);

        u64 U64 = RNG.U64(); // printf("\tu64: %llu\n", U64);
        u32 U32 = RNG.U32(); // printf("\tu32: %u\n",   U32);
        f64 F64 = RNG.F64(); // printf("\tf64: %f\n",   F64);
        u64 R64 = RNG.RangeU64(20, 98); // printf("\trange_u64: %llu\n", R64);
    }

    return 0;
}
