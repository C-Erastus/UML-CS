#include <iostream> 
// This program computer the factorial of a number given by the user. 
void computeFactorial(signed long long int val); 

int main(int argc, char** argv){
	
	signed long long int val; // built-in integer type with the largest range.
	for(;;){
		std::cout << "\nEnter an integer number: ";
		std::cin >> val; 
		computeFactorial(val); 
	}
	return 0; 
}
void computeFactorial(signed long long int val){
	//std::cout << "The function is working" << std::endl;
	int i = 1;
	int count = 1, num = 1; 
	// Doing the computation with a while loop
	while ( i <= val){
		count *= i;
		i++;	
	} 
	std::cout << "The factorial with a while loop is: " << count << std::endl; 

	// Doing the computation with a for loop; 
	for(int i = 1; i <= val; i++){
		num *= i;
	}
	std::cout << "The factorial with a for loop is: " << num << std::endl; 
}
