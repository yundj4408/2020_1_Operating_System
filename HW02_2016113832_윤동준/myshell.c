#include <stdio.h>
#include <unistd.h> 		//To use fork() and exec()
#include <sys/wait.h>		//To use wait()
#include <string.h>			//To use strcmp()
int main (void) {
	char choice[10];
	char* input[10];			//because of the execvp format, you need to get the same input compare to int main(int argc, char* argv[]).
	int count=0;
	char* practice;
	int pid;
	
	
	while(strcmp(choice, "0")!=0){
	printf("\nChoose the System that you want (sum, sub, div, fact) : ");
	scanf("%[^\n]s", choice);		//you get the all the character except enter
	getchar();						//to clear the buffer

	
	
	practice=strtok(choice," ");
	
	
	while(practice != NULL){
		input[count] = practice;
		practice= strtok(NULL, " ");		//dividing by space
		count++;
		
	}	
	
	input[count]=NULL;		//if you use execvp, at the end you should put null
	
	pid = fork();
	if(pid == 0){
				
		if(execvp(input[0], input) == -1) {	//execvp(const char* file, char* const argv[])
			printf("Not Found!");	//input is same as char* argv[].
		}
		
	}
		
	wait(NULL);						//until child process end wait 안쓰면 while을 사용했어서 while문이 계속 돈다.  
	
	
	printf("\nContinue = 1, End = 0 : ");
	scanf("%s", choice);
	
	count=0;
	
	getchar();
	
}	 	
	
	return 0;
}
