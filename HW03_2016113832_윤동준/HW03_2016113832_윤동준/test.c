#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>		//to use pthread function

volatile int first;


void add () {
	int count =0;
	for (int j=0; j<10; j++) {
	while (count < 1000) {				//for delay
		count++;					
		}
	printf("+ ");						//to see add works well
	first++;
	}
}
void sub () {
	int count =0;
	for (int j=0; j<10; j++) {
	while (count < 1000) {				//for delay
		count++;
		}
	printf("- ");						//to see sub works well
	first--;
	}
}
	
void PrintProcess() {
	printf("Process [%d]\n", first);
	}

void *ThreadAdd(void *unuse) {
	
	add();
	
	}
	
void *ThreadSub(void *unuse) {
	
	sub();
	
	}
	
void *ThreadPrint(void *unuse) {
	
	PrintProcess(); //when the process starts, print process[first]
}


int main (int argc, char* argv[]) {
	int i, j, End;
	pthread_t TidFirst, TidAdd[5000];
	pthread_t TidSub[5000];
	
	
	if( argc <2 )
		printf	("Usage: Prtest 0 100");
	first = atoi(argv[1]);	
	End = atoi(argv[2]);
	
	pthread_create(&TidFirst, NULL, ThreadPrint, NULL);		//made PrintThread
	printf("Process [%d]\n", first);						
	for (j=0; j<30; j++) {									
		for (i=0; i<End; i++) {								//made Add Thread, Sub Thread
			pthread_create(&TidAdd[i], NULL, ThreadAdd, NULL);
			printf("\n[+Create [%d]-%d %d", j, i, first);
			pthread_create(&TidSub[i], NULL, ThreadSub, NULL);
			printf("\n[-Create [%d]-%d %d", j, i, first);
		}													//by using for(), I made 5000 thread for add and sub
		printf("\nCreate Loop %d\n", j);					//show the process of loop
		for (i=0; i<End; i++){								//made Add Thread join, Sum Thread join
			pthread_join(TidAdd[i], NULL);
			printf("\n[+Join [%d]-%d %d", j, i, first);
			pthread_join(TidSub[i], NULL);
			printf("\n[-Join [%d]-%d %d", j, i, first);
		}							
		printf("\nJoin Loop %d\n", j);
		
	}
	pthread_join(TidFirst, NULL);
	return 0;
}
