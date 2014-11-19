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
    printf("HURRRR\n");
    fgets(input,sizeof(input),stdin);
    printf("you put in: %s",input);
    printf("errno:%d\n",errno);
  }
  return 0;

}
