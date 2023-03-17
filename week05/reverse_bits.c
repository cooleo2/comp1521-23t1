#include <assert.h>
#include <stdio.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits
typedef unsigned int Word;

Word reverse_bits(Word value) {
    printf("0x%X\n", value);
    Word result = 0x0;
    int NUM_BITS  = sizeof(Word) * 8;

    for (int i = 0; i < NUM_BITS; i++) {
        // Extracted bit no i
        Word bit = value & (0x1 << i);
        bit = bit >> i;
        printf("%d bit no\n", i);
        // Put it into result
        result |= (bit << (NUM_BITS - 1 - i));
    }
    printf("0x%X\n", result);
    return result;
}

int main(void) {
    assert(reverse_bits(0xFFFFFFFF) == 0xFFFFFFFF);
    assert(reverse_bits(0x00000000) == 0x00000000);
    assert(reverse_bits(0x1) == 0x80000000);
    assert(reverse_bits(0x2) == 0x40000000);
    assert(reverse_bits(0x01234567) == 0xE6A2C480);
    printf("All tests passed!\n");
    return 0;
}
