#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include <string.h>
#include "bashell.h"

//it is all genji's fault


/*
 * The main umbrella function that parses through the given string command.
 * Executed every the user sends in a command through fgets.
 * Features to include first :
 * 	Just semicolon (;) chaining.
 * 	Multiple pipes.
 * 	Redirection.
 */
int process(char * cmd) {	

	//Define redirection operators
	char * opers_redir[256];
	
	int x;
	for (x=0;x<sizeof(opers_redir)/sizeof(opers_redir[0]);x++) {
		opers_redir[x] = (char *)malloc(128*sizeof(char));
	}
	
	strcpy(opers_redir[0], ">");
	strcpy(opers_redir[1], "1>");
	strcpy(opers_redir[2], ">>");
	strcpy(opers_redir[3], "1>>");
	strcpy(opers_redir[4], "&>");
	strcpy(opers_redir[5], "&>>");
	strcpy(opers_redir[6], "<");
	strcpy(opers_redir[7], "|");

	//Semicolon chaining
	char * exe;
	int return_status;
	int i=0;
	do {
		exe = stringsep ( &cmd, ";" ); //using stringsep instead of strsep in preparation for later implementations
		return_status = process_redir( &exe, opers_redir);	

	} while ( cmd );	
		
}

/*
 * Test function. Essentially a run with redirection implementation.
 * Operators to include:
 * 	>,1> redirect stdout to a file. Truncates the file.
 * 	>>,1>> redirect stdout to a file. Appends to the file.
 * 	&> redirect everything to a file. Truncates the file.
 * 	&>> redirect everything to a file. Appends to the file.
 * 	< get stdin from the preceding file.
 * 	| gets the stdout from the first command and pipes it into stdin of the second file.
 *	
 * 	Run the function,  
 */
int process_redir (char ** cmd, char * opers[])
{
	int x;
	char *tmp;
	char * min_addr=0; // The address of the first found operator.
	char * min_2_addr=0; // The address of the second found operator.
	int min_oper=0; // The position of the first operator to show up.
	int min_2_oper=0; //The position of the second operator found.
	printf("Length of opers array : %d\n",sizeof(*opers)/sizeof(*(opers[0])));
	for ( x=0; x < (sizeof(*opers)/sizeof(**opers)); x++ ) {
		tmp = strstr( *cmd, opers[x] );
		if ( tmp ) {	
			if (min_addr==0) {
				min_addr = tmp;
				min_oper = x;
			else if (min_2_addr==0) {
				min_2_addr = tmp;
				min_oper = x;
			} else if (tmp<min_addr) {
				min_addr = tmp;
				min_oper = x;
			} else if (tmp<min_2_addr) {
				min_2_addr = tmp;
				min_2_oper = x;
			}				

		}
	
		printf("Searching for : %s\n",opers[x]);
	}

	
	printf("min_addr : %d\n",min_addr);
	printf("min_oper : %d\n",min_oper);
	printf("min_2_addr : %d\n",min_2_addr);
	printf("min_2_oper : %d\n",min_2_oper);
	printf("cmd: %s\n",*cmd);	
	printf("\n\n");

	int status;
	if (min_addr == 0) {
		status = run_redir(*cmd);
		printf("Done running.\n");
	} else {
		char * cmd1;
		char * cmd2;
	
		//Basically stringsep.	
		cmd1 = *cmd;
		min_addr[0]=NULL;
		cmd2 = min_addr + sizeof( *(opers[min_oper]) );
		
		if (min_2_addr) {
			min_2_addr[0]=NULL;
			*cmd = min_2_addr + sizeof( *(opers[min_2_oper]) );
		} else {
			*cmd = NULL;					
		}
		printf("cmd1 : %s\n",cmd1);
		printf("cmd2 : %s\n",cmd2);
		printf("*cmd : %s\n",*cmd);
			
		//I should probably split this into separate functions.  
		switch (min_oper) {
		case 0:
		case 1:
			//>,1>
			run_redir(cmd1);
			printf("done running.\n");
			break;
		case 2:
		case 3:
			//>>,1>>
			break;
		case 4:
			//&>
			break;
		case 5:
			//8>>
			break;
		case 6:
			//<
			break;
		case 7:
			//|
			break;
		default:
			fprintf(stderr,"-znshell: something bad happened here.");
		}

	}
}	

int run_redir(char * cmd)
{
	return run_exec(cmd,run_child);	
}


int run_child( char * cmd )
{

	char * cmdname;
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
	execvp(cmdname,args);
	printf("Done execing\n");
	exit(0);

}
int run_exec(char * cmd, CHILD_FUNC childfunc)
{
	int f;
	int *i;

	//printf("hurr\n");

	f = fork();
	if (!f) {
		childfunc( cmd );
	} else {
		int status;
		waitpid(f,&status,0);
		return status;
	}
}


