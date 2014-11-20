#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include <string.h>
#include "bashell.h"

//it is all genji's fault

int run(char * cmd) {
	run_exec(cmd);
}

int run_exec(char * cmd) {
	int f;
	int *i;

	printf("hurr\n");

	f = fork();
	if (!f) {
		printf("Running execlpc\n");
		char * cmdname;
		cmd = strsep(&cmd,"\n");
		cmdname = strsep(&cmd," ");
		
		printf("execlp(%s,%s,%s,NULL);",cmdname,cmdname,cmd);
		execlp(cmdname, cmdname,cmd, NULL); //No parsing yet. Just for testing.
		printf("Done execing\n");
		exit(0);
	} else {
		int status;
		waitpid(f,&status,0);
	}
}
