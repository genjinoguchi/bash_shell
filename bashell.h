#include <stdlib.h>
#include <stdio.h>

//Run general shell functions
int run(char *);
int store_cmd(char *);
int get_cmd(char *,int num);

//Specialized functions
int run_cd(char *);
int run_exit();

//Swag
int split();
int vsplit();
 
