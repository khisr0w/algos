/*  +======| File Info |===============================================================+
    |                                                                                  |
    |     Subdirectory:  /src                                                          |
    |    Creation date:  5/24/2024 8:59:06 PM                                          |
    |    Last Modified:                                                                |
    |                                                                                  |
    +======================================| Copyright © Sayed Abid Hashimi |==========+  */

#define _TestArray(Array, Ground, TestName) \
    for(u32 Idx = 0; Idx < ArrayLength(Ground); ++Idx) { \
        Assert(Ground[Idx] == Array[Idx], "Failed: " ## TestName);\
    } \

internal void
TestInsertionSort() {
    i32 Array[]  = {5, 2, 4, 6, 1, 3};
    usize ArrayLen = ArrayLength(Array);

    InsertionSort(Array, ArrayLen, ArrayLen, true);

    printf("{ ");
    for(u32 Idx = 0; Idx < ArrayLen-1; ++Idx)
        printf("%i, ", Array[Idx]);
    printf("%i }\n", Array[ArrayLen-1]);

    i32 Ground[]  = {1, 2, 3, 4, 5, 6};
    usize GroundLen = ArrayLength(Ground);
    Assert(GroundLen == ArrayLen, "Failed: test_InsertionSort");
    _TestArray(Array, Ground, "TestInsertionSort");

    printf("\nSuccess: test_InsertionSort\n");
}

internal void
TestAddBinaryInteger() {
    u8 ABinary[4] = {1, 1, 1, 0};
    u8 BBinary[4] = {1, 1, 0, 1};
    u8 ABSumBinary[5];

    AddBinaryInteger(ABinary, ArrayLength(ABinary), BBinary, ArrayLength(BBinary),
                     ABSumBinary, ArrayLength(ABSumBinary));
    u32 Decimal = BinaryArrayToU32(ABSumBinary, ArrayLength(ABSumBinary));
#if 0
    printf("Binary Result:\n");
    printf("\t{");
    for(usize Idx = 0; Idx < ArrayLength(ABSumBinary)-1; ++Idx) {
        printf(" %d,", ABSumBinary[Idx]);
    }
    printf(" %d }\n", ABSumBinary[ArrayLength(ABSumBinary)-1]);

    printf("Decimal Result:\n");
    printf("\t%d", Decimal);
#endif
    Assert(Decimal == 27, "Failed: TestAddBinaryInteger");

    printf("\nSuccess: test_InsertionSort\n");
}
