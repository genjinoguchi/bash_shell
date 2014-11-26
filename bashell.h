#include <stdlib.h>
#include <stdio.h>

//Run general shell functions
int run(char *);
int process(char *);
int run_chain(char *,char *);
int store_cmd(char *);
int get_cmd(char *,int num);

//Specialized functions
int run_cd(char *);
int run_exit();

//Helper Functions
char * fullstrsep(char **, char * query);

//Swag
int split();
int vsplit();
 
