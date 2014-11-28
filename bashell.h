#include <stdlib.h>
#include <stdio.h>

//Function pointers
typedef void (* CHILD_FUNC) (char *);

//Run general shell functions
int run(char *);
int process(char *);
int store_cmd(char *);
int get_cmd(char *,int num);
int run_redir(char *,);
int run_child(char *);
int run_exec(char *, CHILD_FUNC);

//Specialized functions
int run_cd(char *);
int run_exit();

//Helper Functions
char * stringsep(char **, char *);
int run_redir( char * );

//Swag
int split();
int vsplit();
 
