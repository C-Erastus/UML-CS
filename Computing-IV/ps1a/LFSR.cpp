#include <iostream>
#include "LFSR.hpp"

/** 
 * GENERATE EACH NEW BIT BY XOring THE LEFTMOST BIT AND THE TAB BIT
 * THE POSITION OF THE TAP BIT COMES FROM THE CONSTRUCTOR ARGUMENT.
 * */
LFSR::LFSR(std::string seed, int t){
    //std::cout << "Calling the LSFR construct" << std::endl;
    stringSeed = seed; 
    tabBit = t; 
}

int LFSR::step(){
    ///std::cout << "This is the step function" << std::endl; // STUB FUNCTION 
    /*  (1)---> find the bit being shifted off ( THE LAST BIT OF THE STRING )
        (2) --> find the tabBit
        (3) --> XOR the bit being shifted off & tab bit.
        (4) --> shift the initial seed over by one 
        (5) --> add the XOR bit back in the seed
        (6) --> Return the XOR bit (the right most bit)
    */
   
   // iterate of the string and find the last bit or us the stl build in functon.

   /**** START HERE --> FIX THE XOR BIT AND THE PROGRAM SHOUDL WORK **************/
    //std::cout << "The initial seed: " << stringSeed << std::endl; 
   int size = stringSeed.size(), i; //size = 10; 
   //std::cout << "initial size: " << size << std::endl; 
   
   std::string temp;
   char xorBit;
   int temp1 = 0, temp2 = 0, temp3 = 0; 
   int key = size - tabBit;
   key = key-1;
   //std::cout << "Must be the tabBit: " << key << std::endl;

   char dropBit = stringSeed[0]; // fig this
   //std::cout << "The dropBit: " << dropBit << std::endl;

   char tBit = (char)stringSeed[key];
   //std::cout << "This is the tabBit: " << tBit << std::endl; 

   // cast the dropbit to an integer
   temp1 = static_cast<int>(tBit); 
  // std::cout << "temp1: " << temp1 << std::endl; 
   // cast the tabbit to an integer.
   temp2 = static_cast<int>(dropBit);
   //std::cout << "Temp2: " << temp2 << std::endl;

   temp1 = temp1 - '0';
   //std::cout << "This is the new temp1: " << temp1 << std::endl; 
   
   temp2 = temp2 - '0';
  // std::cout << "This is the new temp2:  " << temp2 << std::endl; 
   temp3 = temp1^temp2; 
   //std::cout << "temp3: " << temp3 << std::endl; 
   xorBit = temp3 + '0';
   //std::cout << "The xorBit: " << xorBit << std::endl;

   for(i = 1; i < size; i++){
       temp.push_back(stringSeed[i]);
   }
   temp.push_back(xorBit);
  // std::cout << "temp: " << temp << " " << temp3 << std::endl; 
   
   stringSeed = temp; 

    return temp3; // return the XOR bit
}
/* IMPLEMENT THE GENERATE() FUNCTIOION BY CALLING THE STEP() FUNCTION K TIMES
*/
int LFSR::generate( int k){
    int val = 0, bit = 0, i; 
    //std::cout << "This the generate function" << std::endl; 
    for(i = 0; i < k; i++){
        bit = step();
        val = val + val; 
        val = val + bit;
    }
    std::cout << stringSeed << " " << val <<  std::endl; 


    return val;
}

/* OVERLOADING THE  << OPERATOR */ 
/*  WHEN CALLED, THIS FUNCTION WILL DISPLAY ITS CURRENT REGISTER VALUE IN PRINTABLE FORM */ 
std::ostream& operator<< (std::ostream& out, const LFSR& lsfr){

       for( int i = 0; i < 10; i++){

        out << lsfr.stringSeed ;
    }
    return out; 
}

/**** ADDITIONAL MEMBER FUNCTION ***********/
/*void LFSR::displayStep(){
    
    int i; 
    for(i = 0; i < 10; i++){
        // call the step function
        step(); 
        std::cout << stringSeed << " " << std::endl; 

    }
}*/
