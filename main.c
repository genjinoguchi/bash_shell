#include <stdio.h>
#include <stdlib.h>

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include <errno.h>
#include <string.h>

#include "bashell.h" 

static void sighandler(int signo) {
  if (signo==SIGINT) {
	printf("Nice try.\n");
	exit(3);
  }	
}

int main() {  
  char input[256];

  signal(SIGINT, sighandler);
  while(1){
    //printf("maybeit'sthisshit\n");
    char * cwd;
    getcwd(cwd,256);
    char * sepcwd;
    printf("%s\n",cwd);
    while(cwd){
      //printf("wtfisthisshit\n");
      sepcwd = strsep(&cwd,"/");
    }
    
    
    printf("%s$:  ",sepcwd);
	fgets(input,sizeof(input),stdin);
	//printf("you put in: %s",input);
	if(errno) {
		printf("errno:%s\n",strerror(errno));
	} else {
	  //printf("Running things.\n");
		run(input);
	}
  }
  return 0;

}
