#include <stdio.h>
#include <stdlib.h>
int main(){
    int** ptr;
	int size1 = 20, size2 = 30; 
    int i, j; 
    /**** STEP 1 -- ALLOCATE SPACE FOR THE BIG ARRAY ****/
   ptr = (int**)malloc(sizeof(int*) *20);
    // check if malloc fails

    /*** STEP 2 --- ITERATE OVER THE BIG ARRAY AND POPULATE IT ****/
    for(i = 0; i < 20; i++){
        ptr[i] = (int*)malloc(sizeof(int) * 30);
        //check if malloc fails; 
    }

    /*** STEP 3 --- POPULATE THE 2D ARRAY ******/
    for( i = 0; i < 20; i++){
        for(j = 0; j < 30; j++){
            ptr[i][j] = i+j; 
        }
    }
    
    /**** STEP 4 --- DISPLAY THE 2D ARRAY *****/
    for(i = 0; i < 20; i++){
        for(j = 0; j < 30; j++){
            printf("%2d ", ptr[i][j]);
        }
        printf("\n");
    }

    /*** STEP 5 --- FREE MALLOC ******/ 
    for( i = 0; i < 20; i++){
        free(ptr[i]);
    } 
    free(ptr);
    return 0;
}
