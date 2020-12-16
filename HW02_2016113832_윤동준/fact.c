#include <stdio.h>
#include <stdlib.h> 							//to use atoi function

int main(int argc, char* argv[]) {
	
	int i=0;
	int fact=1;
	
	if (argc != 2){
		printf("Failed. Try again\n");			//if you type more or less then two string, it will apear "Try again".		
		return 0;
	}
	
	for (i=0; i<atoi(argv[1]); i++) {			//by using atoi function, I made string to integer, and then run for until atoi
		fact=fact*(atoi(argv[1])-i);
	}
	
	printf("%s! = %d\n", argv[1], fact);
	return 0;
}
