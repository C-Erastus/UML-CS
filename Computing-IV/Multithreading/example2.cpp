#include <iostream> 
#include <cstdlib> 
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data{
	int thread_id; 
	char *message; 
}; 

int main(){

pthread_t threads[NUM_THREADS]; 
struct thread_data td[NUM_THREADS]; 
int rc; 
int i; 

for ( i = 0; i < NUM_THREADS; i++){
	cout << "main() : creating thread, " << i << endl; 
	td[i].th
	}
return 0; 
}
