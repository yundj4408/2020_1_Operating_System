#include<stdio.h>
#include<stdlib.h> 						// to use atoi function

int main(int argc, char* argv[]){
	int i;
	int sum;
	
	if(argc!=3){
		printf("Failed!");
		return 0;
	}
	
	sum= atoi(argv[1])+atoi(argv[2]); 
	printf("sum = %d", sum); 
	return 0;
}
