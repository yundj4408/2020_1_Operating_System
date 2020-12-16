#include <stdio.h>
#include <stdlib.h>						//to use atoi function
#include <pthread.h>					//to use pthread function

volatile int first;					


	
void add () {							//to increase first 10 times by using while
	int count =0;		
	
	while (count < 100) {
		first++;
		count++;
	}
}

void sub () {
	int count =0;						//to decrease first 10 times by using while
	
	while (count <100) {
		first--;
		count++;
	}
}

void *ThreadAdd(void *unuse) {			//Made Threadfunction that run add function 
	
	add();
	
	}
	
void *ThreadSub(void *unuse) {			//Made Threadfunction that run sub function
	
	sub();
	
	}


int main (int argc, char* argv[]) {
	int i;
	first = atoi(argv[1]);				//char to integer

		
	pthread_t TidAdd[10000];			//because of segmentation fault, I made array size 10000
	pthread_t TidSub[10000];			
	for (int j=0; j<30; j++) {
		
	for (i=0; i<5000; i++) {			//by using for(), I made 5000 thread for add and sub
	pthread_create(&TidAdd[i], NULL, ThreadAdd, NULL);
	pthread_create(&TidSub[i], NULL, ThreadSub, NULL);
	}									
	
	for (i=0; i<5000; i++) {
	pthread_join(TidAdd[i], NULL);		//wait until the TidAdd[i] ends
	pthread_join(TidSub[i], NULL);
	}		
	
	printf("%d\n", first);				//print first after run TidAdd and TidSub
	
	}
	return 0;
}
