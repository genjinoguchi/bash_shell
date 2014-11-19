#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#include <string.h>

int main() {
  	//printf("Colors: \x1b[0;36;45m Hurrrrrrrr.\n");

	execlp("ls","ls",NULL);
	printf("hurr\n");
	execlp("ls","ls",NULL);		
	if (errno) {
		printf("Error : %s",strerror(errno));
	}
}
/*
0: reset colors/style
1: bold
4: underline
30 - 37: black, red, green, yellow, blue, magenta, cyan, and white text
40 - 47: black, red, green, yellow, blue, magenta, cyan, and white background
*/
