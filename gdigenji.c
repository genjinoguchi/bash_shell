#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include <string.h>
#include "bashell.h"

//it is all genji's fault

int run(char * cmd) {
  
  if (check_cd(cmd)){
    //printf("itgoeshere\n\n\n\n");
    run_cd(cmd);
  } else {
    run_exec(cmd);
  }
}

int check_cd(char * cmd){
  //printf("cmd in check_cd:%s\n",cmd);
  char * cmdcopy;
  strncpy(cmdcopy,cmd,sizeof(cmd));
  
  char * cmdname;
  cmdcopy = strsep(&cmdcopy,"\n");
  cmdname = strsep(&cmdcopy," ");

  //printf("cmd after strsep cmdcopy: %s\n\n",cmd);
  
  if (!(strcmp(cmdname,"cd"))){
    return 1;
  } else {
    return 0;
  }
}

int run_cd(char * cmd){
  //printf("cmd before strsep: %s\n",cmd);
  char * cmdname;
  cmd = strsep(&cmd,"\n");
  cmdname = strsep(&cmd," ");
  //printf("cmd after strsep: %s\n",cmd);
  //now cmd has the path for cd 
  chdir(cmd);

  char newdir[256];
  getcwd(newdir,sizeof(newdir));
  printf("Current dir: %s\n",newdir);
  
  printf("cd should be running now\n");
}

int run_exec(char * cmd) {
	int f;
	int *i;

	//printf("hurr\n");
	
	f = fork();
	if (!f) {
	  //printf("Running execlpc\n\n");
		char * cmdname;
		cmd = strsep(&cmd,"\n");
		cmdname = strsep(&cmd," ");

		char * args[256];
		args[0] = cmdname;
		int x;
		x = 1;
		while (cmd){
		  char * arg = strsep(&cmd," ");
		  args[x] = arg;
		  x++;
		}
		args[x] = NULL;
		/*
		printf("---printing array---\n");
		x = 0;
		while (args[x]){
		  printf("%d: %s\n",x,args[0]);
		  x++;
		}
		printf("---endprint---\n");
		*///debugging the array
		//printf("execvp(%s,array)",cmdname);
		execvp(cmdname,args);
		printf("Done execing\n");
		exit(0);
	} else {
		int status;
		waitpid(f,&status,0);
	}
}


