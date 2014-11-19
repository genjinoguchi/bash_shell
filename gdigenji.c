#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include "bashell.h"

//it is all genji's fault

int run(char * command){
  execlp(command,command,NULL);
}

