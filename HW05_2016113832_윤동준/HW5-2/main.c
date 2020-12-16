#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char** argv){
	int fd = -1;
	
	
	if(argc != 1){						
		printf("type ./main\n");
		exit(0);	
	}
	fd =open("/dev/ledtest", O_RDWR);
	
	while(1){								//infinite loading. wait until the getting switch value
		write(fd, NULL, NULL);		
			}
	close(fd);
}
