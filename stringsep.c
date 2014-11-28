#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "bashell.h"


/*
This is a function similar to strsep. It searches through a given string for the entire search query (not just one of the chars).
params: char ** str -> input string
		char *  query-> search query
It returns a pointer to the original string and puts NULL in the first place where the search query was found.
str is set to the first position after the found search query.
*/

char * stringsep  (char ** str, char * query)
{
	char * first;	
	
	first = *str;
	*str = strstr( *str, query);
	if (*str) {
		**str = 0;	
		*str += sizeof(*query);
	}
	
	return first;
}

/*
int main() {
	char * test1;
	char * test2;


	test1 = strcpy(test1, "Hello world! || Goodbye world!");	

	test2 = stringsep( &test1, "|");
	printf("test1: %s\n",test1);
	printf("test2: %s\n",test2);	

	return 0;
}
*/
