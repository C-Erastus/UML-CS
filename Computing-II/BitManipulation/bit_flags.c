#include <stdio.h>
/***********************************************************
Author: Chukpozhn Toe
Date: 03/13/2018
Effort: 8+ hours, I lost count
Purpose: Practice with bit flags.
Interface proposal: A test functoin call display bits to see if the code works. 
***********************************************************/
#include <stdlib.h>
#include "bit_flags.h"

struct bit_flag{

	int capacity; //Number of elements the container can hold without a resize.
	int size; //Number of elements the container holds right now
	int* data;
};
typedef struct bit_flag Bit_flag;

//declare how big is an integer
const int INIT_SIZE = sizeof(int) * 8; 

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits){
	Bit_flag* pBit_flags = NULL;

	pBit_flags = (Bit_flag*)malloc(sizeof(Bit_flag));
	if(pBit_flags != NULL){				
		pBit_flags->size = number_of_bits;
		pBit_flags->capacity = (number_of_bits / INIT_SIZE) + 1; //pluse one
		pBit_flags->data = (int*)malloc(sizeof(int)* pBit_flags->capacity);
		if(pBit_flags->data == NULL){

			free(pBit_flags);
			return NULL;
		}
	}

	return pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position){

	Bit_flag* pBit_flags = (Bit_flag*)hBit_flags;

	int* temp;
	//check if flag_position is less than zero;
	if(flag_position < 0){
		return FAILURE;
	}

	if(flag_position >= pBit_flags->capacity * INIT_SIZE){
		temp = (int*)malloc(sizeof(int) * (flag_position / INIT_SIZE)); //in terms of data index or in terms of regular index
		if(temp == NULL ){

			return FAILURE;
		}
		for(int i = 0; i < (flag_position / INIT_SIZE); i++){
			temp[i] = 0;
		}
		for(int i = 0; i < pBit_flags->capacity; i++){
			temp[i] = pBit_flags->data[i];
		}
		free(pBit_flags->data);
		pBit_flags->data = temp;
		pBit_flags->capacity = (flag_position / INIT_SIZE) + 1; //update capacity
		}
	//set flags
	pBit_flags->data[flag_position / INIT_SIZE] |= (1 << flag_position % INIT_SIZE);

	if(flag_position > pBit_flags->size){

		pBit_flags->size = flag_position + 1;
	}

	return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position){

	//cast to the know type
	Bit_flag* pBit_flags = (Bit_flag*)hBit_flags;

	int* temp; 

	if(flag_position < 0){
		return FAILURE;
	}
	if(flag_position >= pBit_flags->capacity * INIT_SIZE){
		temp = (int*)malloc(sizeof(int) * (flag_position / INIT_SIZE));
		if(temp == NULL){

			return FAILURE;
		}
		for(int i = 0; i < (flag_position / INIT_SIZE); i++){
			temp[i] = 0;
		}
		for(int i = 0; i < pBit_flags->capacity; i++){
			temp[i] = pBit_flags->data[i];
		}
		free(pBit_flags->data);
		pBit_flags->data = temp;
		pBit_flags->capacity = (flag_position / INIT_SIZE);
	}
	pBit_flags->data[flag_position / INIT_SIZE] &= ~ (1 << (flag_position % INIT_SIZE));

	//the new size is the index of the largest bit previously set. 

	//pBit_flags->size;
	return SUCCESS;
}
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position){
	//cast to the known type; 
	Bit_flag* pBit_flags = (Bit_flag*)hBit_flags; 
	int val = 1 & (pBit_flags->data[flag_position / INIT_SIZE] >> flag_position);// odd code, redo 

	return val; 
}
// this funct return the object size
int bit_flags_get_size(BIT_FLAGS hBit_flags){
	//cast to the know type
	Bit_flag* pBit_flags = (Bit_flag*)hBit_flags;

	return pBit_flags->size; 
}
//this function return the object capactiy.
int bit_flags_get_capacity(BIT_FLAGS hBit_flags){

	Bit_flag* pBit_flags = (Bit_flag*)hBit_flags;

	return pBit_flags->capacity * INIT_SIZE;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags){

	Bit_flag* pBit_flags = (Bit_flag*)*phBit_flags;
	free(pBit_flags->data);
	free(pBit_flags);

	*phBit_flags = NULL; 
}

