#include <stdio.h>
#include <stdlib.h>												// to use atoi function

int main(int argc, char* argv[]) {
	
	int sub=0;
	
	if (argc != 3)
	{
		printf("Failed. Try again");							//if you type more or less then three string, it will apear "Try again".
		return 0;
	}
	
	if (atoi(argv[1])>atoi(argv[2]))							//if the number which argv[1] is greater then argv[2], then sub argv[1]-argv[2]
	{
		sub= atoi(argv[1])-atoi(argv[2]);
		printf("%s - %s = %d\n",argv[1], argv[2], sub);
	}
	
	else {														//if the number which argv[2] is greater then argv[1], then sub argv[2]-argv[1]
		sub= atoi(argv[2])-atoi(argv[1]);	
		printf("%s - %s = %d\n", argv[2], argv[1], sub);
		}
	printf("%s", argv[0]);	printf("%s", argv[1]);	printf("%s", argv[2]);
	return 0;
}
