/**********************************************************************
Program: Daily7
Time spent: 3 hours 
Purpose: Practice with stack data structure. 
NOTE TO SELF: This assignment wasn't hard at all. Understanding how stack
				works was major part of solving the problem. The rest was
				simply just logic. 
				
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void clear_keyboard_buffer(); 
void process_test_cases(STACK hStack);
int main(int argc, char* argv[]){

	STACK hStack;
	Status status; 
	hStack = stack_init_default(); 
	int number_of_cases, i;
	scanf("%d", &number_of_cases);
	clear_keyboard_buffer(); 
	for( i = 0; i < number_of_cases; i++){
		process_test_cases(hStack); 
		while (!stack_empty(hStack)){
			stack_pop(hStack);
		}
	}
	stack_destroy(&hStack);
	return 0;
}
void process_test_cases(STACK hStack){
	Status status; 
	int count = 0;
	char c; 

	scanf("%c", &c);//if I clear the keyboard buffer here, my loop only runs ones.
	while( c != '\n'){

		switch( c ){ //in my switch statement it tells me yes for every possible yes. but I only want it to tell me yes onece. 
			case '(':
				stack_push(hStack, c);
				break; 
			case ')':
				if(stack_top(hStack, &status)!= '(' || stack_empty(hStack)){
					printf("No\n");
					clear_keyboard_buffer();
					return;
				}
				stack_pop(hStack);
				count++;
				break;
			case '[':
				stack_push(hStack, c);
				break;
			case ']':
				if(stack_top(hStack, &status)!= '[' || stack_empty(hStack)){
					printf("No\n");
					clear_keyboard_buffer();
					return;
				}
				stack_pop(hStack);
				count++;
				break;
			case '{':
				stack_push(hStack, c);
				break;
			case '}':
				if(stack_top(hStack, &status) != '{' || stack_empty(hStack)){
					printf("No\n");
					clear_keyboard_buffer();
					return;
				}
				stack_pop(hStack);
				count++;
				break;
		}
		scanf("%c", &c);// If I clear the keyboard buffer here I get an infinit loop
	}
	if(stack_empty(hStack)){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
}
void clear_keyboard_buffer(){
	char c; 
	int noc; 
	noc = scanf("%c", &c); 
	while( noc == 1 && c != '\n'){
		noc = scanf("%c", &c); 
	}
}
