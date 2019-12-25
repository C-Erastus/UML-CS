#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <cstdint>
using namespace std; 

#define NUM_THREADS 5

void *PrintHello(void *threadid){
	long tid; 
	tid = (long)threadid; 
	cout << "Hello World! Thread ID, " << tid << endl; 
	pthread_exit(NULL); 
}
int main(){

pthread_t threads[NUM_THREADS]; 
int rc = 0; 
int i = 0; 

for( i = 0; i < NUM_THREADS; i++){
	cout << "main() : creating thread, " << i << endl; 
	rc = pthread_create(&threads[i], NULL, PrintHello, (void *)(uintptr_t)(i));

	if(rc){
		cout << "error:unable to create thread," << rc << endl;
		exit(1); 
	}
	}
pthread_exit(NULL);

return 0;
}

