#include <stdio.h>
#include <stdlib.h> 
#include "my_string.h"

struct my_string{
	int size; 
	int capacity;
	char* data; 
};
typedef struct my_string My_string;

MY_STRING my_string_init_default(void){
	My_string* pMy_string; // create a pointer to the string object. 
	pMy_string = (My_string*)malloc(sizeof(My_string)); // Allocate space for the string object
	if(pMy_string != NULL){ // Check if malloc return NULL
		pMy_string->size = 0;
		pMy_string->capacity = 7;
		pMy_string->data = (char*)malloc(sizeof(char)* pMy_string->capacity);
		if(pMy_string->data == NULL){
			free(pMy_string);
			return NULL;  
		}
		return pMy_string; // return the address of the string opject
	}
	return NULL; // return NULL on failure 
}

void my_string_destroy(MY_STRING* phMy_string){
	My_string* pMy_string = (My_string*)*phMy_string;
	free(pMy_string->data); // free the string data
	free(pMy_string); // free string object itself.
	*phMy_string = NULL; // set the handle to NULL  
}

MY_STRING my_string_init_c_string(const char* c_string){
	My_string* pMy_string; 
	int size = 0; 
	for(int i = 0; c_string[i] != '\0'; i++){
		size+=i; // get the size of the string
	}
	pMy_string = (My_string*)malloc(sizeof(My_string)); 
	if(pMy_string != NULL){
		pMy_string->size = size; 
		pMy_string->capacity = size+1;
		pMy_string->data = (char*)malloc(sizeof(char)*pMy_string->capacity);
		if(pMy_string->data == NULL){
			free(pMy_string);
			return NULL; 
		}
		pMy_string->data = c_string;
		return pMy_string; 
	}
	return NULL; 
}

int my_string_get_capacity(MY_STRING hMy_string){
	My_string* pMy_string = (My_string*)hMy_string; 
	return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string){
	My_string* pMy_string = (My_string*)hMy_string; 
	return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
	My_string* pLMy_string = (My_string*)hLeft_string; 
	My_string* pRMy_string = (My_string*)hRight_string;
	
	if(pLMy_string->data == pRMy_string->data){ // if the string are the same return 0
		return 0; 
	} 
	for(int i = 0; i < pLMy_string->size; i++}{
		if (pLMy_string->data[i] > pRMy_string->data[i]){
			return -1; // if the left string is bigger return -1
		}
	}

}
