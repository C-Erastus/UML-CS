#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

void clear_keyboard_buffer();

void print_flags(BIT_FLAGS hBit_flags);

int main(int argc, char* argv[]){
    BIT_FLAGS hBit_flags;
    int flag_position;

    //hBit_flags = bit_flags_init_number_of_bits(0);

    //prompt the user for the flag_position
   scanf("%d" ,&flag_position);
   clear_keyboard_buffer();

    while(flag_position != -1){

	    hBit_flags = bit_flags_init_number_of_bits(flag_position);
	    //printf("%d\n", flag_position);

        bit_flags_set_flag(hBit_flags, flag_position);

        scanf("%d",&flag_position);
        clear_keyboard_buffer();
    }
    print_flags(hBit_flags);

    bit_flags_destroy(&hBit_flags);
    
    return 0;
}
void print_flags(BIT_FLAGS hBit_flags){
    int i, j;

   // printf("Capacity is %d", bit_flags_get_capacity(hBit_flags));
    for(i = 0; i < (bit_flags_get_capacity(hBit_flags) / 32); i++)
    {
        for(j = 0; j < 32; j++)
        {
            if( bit_flags_check_flag(hBit_flags, i * 32 + j) == 1)
            {
                printf("%d\n", i * 32 + j);
            }
       }
    }
}
void clear_keyboard_buffer(){

    char c; 
    scanf("%c", &c);

    while(c !='\n'){
        scanf("%c", &c); 
    }
}
