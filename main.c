#include <stdio.h>
#include <stdlib.h>

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include "bashell.h" 

static void sighandler(int signo) {
	if (signo==SIGINT) {
		printf("Nice try.\n");
	}
}

int main() {
	signal(SIGINT, sighandler);

	while(1) {
		sleep(1);
		printf("Shell running\tPID: %d",getpid());
	

	return 0;
}
