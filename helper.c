#include <stdio.h>
#include <stdlib.h>

#include <string.h>


char *
fullstrsep  (char ** str, char * query)
{
	printf("&: %p\n",str);
	char * first;	
	
	first = *str;
	*str = strstr( *str, query);
	**str = 0;
		
	*str += strlen(query);

	printf("&: %p\n",str);
	printf("first: %s\n",first);
	return first;
}
/*
int main() {
	char * test1;
	char * test2;

	test1 = (char *)malloc(256*sizeof(char));

	test1 = strcpy(test1, "Hello world! || goodbye world!\0");	

	test2 = fullstrsep( &test1, "||");
	printf("test1: %s\n",test1);
	printf("test2: %s\n",test2);	

	return 0;
}
*/
