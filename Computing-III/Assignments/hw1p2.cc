// This program print out all the commandline argument given to it
#include <iostream> 

int main(int argc, char** argv){
	
	for(int i = 0; argv[i] != '\0'; i++){
		std::cout << argv[i] << std::endl; 
	}
}
