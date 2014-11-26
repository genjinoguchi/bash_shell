#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#include <string.h>

int main() {

	char * test;
	char * test2;

	test = (char *)malloc(256 * sizeof(char));
	strcpy(test, "hello world | goodbye world!");
	

	test2 = strsep( &test, "|");

	printf("test: %s\t, test2: %s\n",test, test2);	



	/*
  	//printf("Colors: \x1b[0;36;45m Hurrrrrrrr.\n");

	execlp("ls","ls",NULL);
	printf("hurr\n");
	execlp("ls","ls",NULL);		
	if (errno) {
		printf("Error : %s",strerror(errno));
	}
	*/
}
/*
0: reset colors/style
1: bold
4: underline
30 - 37: black, red, green, yellow, blue, magenta, cyan, and white text
40 - 47: black, red, green, yellow, blue, magenta, cyan, and white background
*/
