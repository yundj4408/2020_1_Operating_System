#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> //for sleep function usleep

void main(int argc, char** argv){
	char buf[BUFSIZ];
	char i = 0;
	char mode[BUFSIZ];
	int fd = -1;
	char led_control[BUFSIZ];
	
	fd =open("/dev/ledtest", O_RDWR);
	
	if(argc != 1){
		printf("./main\n");
		exit(0);	
	}
	
	printf("Select the mode, A(blink), B: ");
	scanf("%c", mode);
	

	if (strcmp(mode , "A")==0)
	{
		for (int j=0; j<3; j++) {
		write(fd, "1", 1);			//turn on the led
		usleep(500000);				//wait 0.5 sec
		write(fd, "0", 1);			//turn off the led
		usleep(500000);				//wait 0.5 sec
		}
	}
	
	if (strcmp(mode , "B") == 0) {
		printf("Select 1(ON) or 0(OFF) : ");
		scanf("%s", led_control);
		if (strcmp(led_control,"1") == 0) write(fd, "1", 1);			//turn on the led
		else write(fd, "0", 1);											//turn off the led
		return 0;
	}

	printf("fd: %d\n", fd);
	printf("mode type: %s\n", mode);
	
	close(fd);
}
