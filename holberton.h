#ifndef _SHELL_HOLBERTON_
#define _SHELL_HOLBERTON_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/******Some String operations and manipulation******/
char *_strdup(char *strtodup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
ssize_t _puts(char *str);


#endif /* _SHELL_HOLBERTON_ */