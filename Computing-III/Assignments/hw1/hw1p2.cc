//***** This program prints out all command line arguments given itm
//********** Each on a separate line 

#include <iostream> 

int main(int argc, char** argv){
	int i = 0;
	while(argv[i] != NULL){
		std::cout << argv[0] << std::endl; 
		i++; 
	}
	return 0; 	
}
