/*  +======| File Info |===============================================================+
    |                                                                                  |
    |     Subdirectory:  /src                                                          |
    |    Creation date:  3/29/2024 5:48:43 PM                                          |
    |    Last Modified:                                                                |
    |                                                                                  |
    +======================================| Copyright © Sayed Abid Hashimi |==========+  */

internal void
InsertionSort(i32 *Array, usize ArraySize, usize N, bool Ascending) {
    /* NOTE(Abid):
     * Params:
     *     Array: Array to be sorted.
     *     ArraySize: Size of the array.
     *     N: Sort N number of initial values within Array (subarray)
     *     Ascending: Changes i32 sign to inverse the comparisons.
     */

    Assert(ArraySize >= N, "cannot sort more than array size");

    i32 Asc = Ascending ? 1 : -1;
    for(u32 Idx = 1; Idx < N; ++Idx) {
        i32 Key = Array[Idx] * Asc;
        u32 Jdx = Idx;
        while ((Jdx > 0) && (Array[Jdx-1]*Asc > Key)) {
            Array[Jdx] = Array[Jdx-1];
            --Jdx;
        }
        Array[Jdx] = Key * Asc;
    }
}

typedef struct {
    bool Found;
    usize Index;
} lin_search;
internal lin_search
LinearSearch(i32 *Array, u32 ArraySize, i32 Value) {
    lin_search Result = {0};

    for(Result.Index = 0; Result.Index < ArraySize; ++Result.Index) {
        Result.Found = Array[Result.Index] == Value;
        if(Result.Found) break;
    }

    return Result;
}

internal void
AddBinaryInteger(u8 *A, usize ALen, u8 *B, usize BLen, u8 *C, usize CLen) {
    Assert((ALen == BLen) && (ALen == CLen-1), "array lengths do not match");

    u8 Remainder = 0;
    for(usize Idx = ALen; Idx > 0; --Idx) {
        C[Idx] = (A[Idx-1] ^ B[Idx-1]) ^ Remainder;
        Remainder = ((A[Idx-1] & B[Idx-1]) || ((A[Idx-1] | B[Idx-1]) & Remainder));
    }
    C[0] = Remainder;
}

internal u32
BinaryArrayToU32(u8 *A, usize ALen) {
    u32 Result = 0;

    u32 Base = 1;
    for(usize Idx = ALen; Idx > 0; --Idx) {
        Result += A[Idx-1]*Base;
        Base *= 2;
    }

    return Result;
}
