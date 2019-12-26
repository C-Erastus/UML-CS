#include <stdio.h>
#include <stdlib.h> 
#include "my_string.h"

int main(int aregc, char** argv){
	
	MY_STRING hMy_string = NULL; 
	
	hMy_string = my_string_init_default();
	
	hMy_string = my_string_init_c_string("hi");

	my_string_destroy(&hMy_string); 
	return 0;
}
