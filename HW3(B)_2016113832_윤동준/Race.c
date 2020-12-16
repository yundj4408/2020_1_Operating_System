#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>					//to use pthread function

volatile int first;

pthread_mutex_t mutex_lock; 			//declare mutex object

void add () {
	
	int count =0;
	
	while (count < 10) {
		first++;
		count++;
	}
}

void sub () {
	int count =0;
	
	while (count <10) {
		first--;
		count++;
	}
}

void swap()								//(Important HW3(B) Question1)to see race condition eventhough number of threads are not that big
{
	int temp;
	for (int i=0; i<10000; i++) {
		temp = first;
		first = temp;
	}
}

void *ThreadAdd(void *unuse) {
	pthread_mutex_lock(&mutex_lock);	//critical section start
	add();
	swap();								//add swap function to make race condition
	pthread_mutex_unlock(&mutex_lock);	//critical section end
	}
	
void *ThreadSub(void *unuse) {
	pthread_mutex_lock(&mutex_lock);	//critical section start
	sub();
	swap();								//add swap function to make race condition
	pthread_mutex_unlock(&mutex_lock);	//critical section end
	}



int main (int argc, char* argv[]) {
	int i;
	first = atoi(argv[1]);
	pthread_t TidAdd[10];
	pthread_t TidSub[10];				
	for (int j=0; j<30; j++) {
		
	for (i=0; i<5; i++) {				//by using for(), I made 10 threads.
	pthread_create(&TidAdd[i], NULL, ThreadAdd, NULL);
	pthread_create(&TidSub[i], NULL, ThreadSub, NULL);
	}									
	
	for (i=0; i<5; i++) {
	pthread_join(TidAdd[i], NULL);
	pthread_join(TidSub[i], NULL);
	}		
	
	printf("%d\n", first);
	
	}
	return 0;
}

