#include <stdio.h>
#include <stdlib.h>									// to use atoi function

int main(int argc, char* argv[]) {
	
	int div=0;
	int remainder=0;
	
	if (argc != 3){
		printf("Try again");						//if you type more or less then three string, it will apear "Try again".
		return 0;
	}
	
	if (atoi(argv[1]) > atoi(argv[2]))				//if the number which argv[1] is greater then argv[2], then div argv[1]/argv[2] and argv[1]%argv[2]
	{
		div= atoi(argv[1])/atoi(argv[2]);
		remainder= atoi(argv[1]) % atoi(argv[2]);
		printf("%s / %s = %d\n", argv[1], argv[2], div);
		printf("remainder between %s and %s is %d", argv[1], argv[2], remainder);
	}
	
	if (atoi(argv[2])> atoi(argv[1]))				//if the number which argv[2] is greater then argv[1], then div argv[2]/argv[1] and argv[2]%argv[1]
	{
		div= atoi(argv[2])/atoi(argv[1]);
		remainder= atoi(argv[2]) % atoi(argv[1]);
		printf("%s / %s = %d\n", argv[2], argv[1], div);							 
		printf("Remainder Between %s and %s is %d\n", argv[2], argv[1], remainder);
	}
	
	
	
	return 0;
}
