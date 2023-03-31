#include <stdio.h>
#include <stdint.h>
 
typedef struct six_bit_groups {
    uint8_t middle_bits;
    uint8_t lower_bits;
} six_bit_groups_t;
 


/* 
For example:
00000000 00000101 01000000 01110110 
0x 00 05 40 76
 
middle six bits are 101010
 lower six bits are 110110  
*/
 
// TODO
six_bit_groups_t get_bit_groups(uint32_t value) {
    six_bit_groups_t result;

    uint32_t mask = 0x3F; // 0x3F is just 6 1's in binary (0011 1111)
    result.lower_bits = value & mask;

    result.middle_bits = (value >> 13) & mask;


    return result;
}
 
int main(void) {
    six_bit_groups_t result = get_bit_groups(0x00054076);
    printf("lower: 0x%X, upper: 0x%X", result.lower_bits, result.middle_bits);
    return 0;
}
