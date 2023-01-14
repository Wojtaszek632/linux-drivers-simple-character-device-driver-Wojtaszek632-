#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "mydriver.h"
#define MY_IOCTL_IN _IOW('w', 1, my_ioctl_data)

char dane[] = "Hello_from_app";
char *readBuff; 

int main(void) {

	printf("Hello from app!\n");
	
	int fd = open("/dev/my_device_driver", O_RDWR);
	
	if (fd < 0) {	printf("Unable to open driver\n"); 	return 0;	}
	
	printf("Opened driver!\n");
	
	readBuff = (char*)malloc(50);
	my_ioctl_data data ={5,10,addition};
	
	printf("Writing IOCTL!\n");	
	if (ioctl(fd, MY_IOCTL_IN, &data) < 0) {printf("Unable to handle IOCTL\n"); perror("Error:");	return 0;	}
	
		
	if (read(fd, readBuff, 50 ) < 0) {  printf("Unable to read from driver\n");	return 0;	}
		
	printf("RECIVED FROM DRIVER:  ");
	printf("%s",readBuff);
	
   	free(readBuff);
   	
   	

	printf("Time to close\n");
	
	close(fd);
	
	printf("Closed :) Bye\n");
	return 0;
}
