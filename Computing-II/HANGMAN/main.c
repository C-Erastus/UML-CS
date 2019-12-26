#include <stdio.h>
#include <stdlib.h> 

/* Allocate a two dimentional array of integers so that the array has 
   20 rows of 30 integers in each row. Fill up the entire array so that the
   first row contains 0 - 29 the second row contains 1 - 30, the third row 
   contains 2 - 31 and so on till the last row contiains 19-48
*/
int main(int argc, char** argv){

	int** ptr; // A 2D array is a pointer to a pointer
 
	ptr = (int**)malloc(sizeof(int*)*20); // Allocate space for 20 pointers type int
	for(int i = 0; i < 30; i++){
		ptr[i] = (int*)malloc(sizeof(int)*30); // Allocate space for each i
	}
	//***** POLULATE THE ARRRRAY 
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 30; j++){
			ptr[i][j] = i+j; 
		}
	}
	// ***** PRINT THE 2D ARRAY 
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 30; j++){
			printf("%5d", ptr[i][j]); 
		}
		printf("\n"); 
	}
	
	// ***** Free the pointers
	for(int i = 0; i < 20; i++){
		free(ptr[i]); // iterate over ptr and free each ith because each ith is a pointer, 
	}
	free(ptr); 
	
	return 0; 
}
