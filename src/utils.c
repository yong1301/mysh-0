#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  char* tok = NULL;
  char* cpycommand = NULL;
  int len=0, len2=0;  
     
  len = strlen(command);
  cpycommand = (char*)malloc(sizeof(char)*(len+1));
  strcpy(cpycommand, command);
  *argc = 0;
  
// copy command to cpycommand
  
  tok = strtok(cpycommand, " \t\n");
  if (tok == NULL)
  {
    (*argc)++;
    (*argv) = (char**)malloc(sizeof(char*));
    (*argv)[0] = (char*)malloc(sizeof(char));
    strcpy((*argv)[0], "");
    return;
  } 
  while(tok != NULL)
  {
	len2 = strlen(tok);
	(*argv) = (char**)realloc((*argv),sizeof(char*)*(*argc+1));
	(*argv)[*argc] = (char*)malloc(sizeof(char)*(len2+1));	
	strcpy((*argv)[*argc],tok);
	(*argc)++;
	tok = strtok(NULL, " \t\n");
  }
// tokenize
  free(cpycommand);
}
