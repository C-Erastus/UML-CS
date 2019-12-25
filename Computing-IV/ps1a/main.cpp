#include <iostream>
#include "LFSR.hpp"

int main(){

    LFSR lsfr("01101000010", 8);

    std::cout << lsfr; // display current register value in printable form
    std::cout << "**********************WHEN THE STEP FUNCTON IS CALLED 10 TIMES*************" << std::endl; 
   /* for(int i = 0; i < 10; i++){
        lsfr.step();
    }*/
    std::cout << "**********************\n\nWHEN THE GENERATE FUNCTION IS CALLED 10 TIMES***************" << std::endl;
    for( int i = 0; i < 10; i++){
        lsfr.generate(5);
    }
    /* CALL THE THE STEP FUNCTION FIVE TIMES */

    return 0;
}