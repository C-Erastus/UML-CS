#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

void print_flags(BIT_FLAGS hBitFlags);

int main(int argc, char* argv[]){
    BIT_FLAGS hBit_flags;
    hBit_flags = bit_flags_init_number_of_bits(5);

    bit_flags_set_flag(hBit_flags, 0);
    bit_flags_set_flag(hBit_flags, 3);
    bit_flags_set_flag(hBit_flags, 16);
    bit_flags_set_flag(hBit_flags, 31);
    bit_flags_set_flag(hBit_flags, 87);
    bit_flags_set_flag(hBit_flags, 100);
    
    print_flags(hBit_flags);
    printf("\n\n");
    
    bit_flags_unset_flag(hBit_flags, 31);
    //bit_flags_unset_flag(hBit_flags, 3);

    bit_flags_unset_flag(hBit_flags, 100);
    
    //bit_flags_set_flag(hBit_flags, 99);
    //bit_flags_set_flag(hBit_flags, 100);

    int x = bit_flags_get_capacity(hBit_flags);
    printf("This the capacity %d\n", x);
    int y = bit_flags_get_size(hBit_flags);
    printf("This the size %d\n\n\n", y);
    
    print_flags(hBit_flags);
    bit_flags_destroy(&hBit_flags);
    
    return 0;
}
void print_flags(BIT_FLAGS hBit_flags){
    int i, j;
    for(i = 0; i < bit_flags_get_capacity(hBit_flags) / 32; i++){
        for(j = 0; j < 32; j++){
            printf("%d", bit_flags_check_flag(hBit_flags, i * 32 + j));
            if((j + 1) % 4 == 0)
                printf(" ");
        }
    printf("\n");
    }
}
