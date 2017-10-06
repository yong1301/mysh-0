#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "commands.h"

int do_cd(int argc, char** argv) {
  int result;

  if (!validate_cd_argv(argc, argv))
    return -1;

  result = chdir(argv[1]);
  
  if(result != 0)
      return -1;

  return 0;
}

int do_pwd(int argc, char** argv) {
  char* cwd;

  if (!validate_pwd_argv(argc, argv))
    return -1;

  cwd = getcwd(NULL, 0);

  if(cwd)
    printf("%s\n", cwd);
  else
    return -1;

  free(cwd);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc == 2)
  {
    if(strcmp(argv[0],"cd"))
	return 0;
    return 1;
  }
  else
    return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc == 1)
  {
    if(strcmp(argv[0],"pwd"))
      return 0;
    return 1;
  }
  else
    return 0;
}
