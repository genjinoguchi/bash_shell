#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int store_cmd(char * cmd) {
	int fd;

	fd = open("cmds", 0_WRONLY | 0_CREAT);
	if (fd) {
		//store the function
	} else {
		printf("Error: %s\n",strerror(errno));
	}

}

char * get_last_cmd(char * cmd, int num) {


}
