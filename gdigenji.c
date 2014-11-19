#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include "bashell.h"

//it is all genji's fault

int run(char * cmd) {
	run_exec(cmd);
}

int run_exec(char * cmd) {
	int f;
	int *i;

	printf("hurr");

	f = fork();
	if (!f) {
		printf("Running execlpc\n");
		printf("execlp(%s,%s,NULL);",cmd,cmd);
		execlp(cmd, cmd, NULL); //No parsing yet. Just for testing.
		printf("Done execing\n");
	} else {
		int status;
		waitpid(f,&status,0);
		printf("\ncash$:  ");
	}
}
