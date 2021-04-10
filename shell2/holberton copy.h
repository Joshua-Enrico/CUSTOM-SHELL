#ifndef _SHELL_HOLBERTON_
#define _SHELL_HOLBERTON_
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>


/**** Estructura con las posibles variables que vamos a usar ****/
/**
 * struct variables - variables
 * @array_tokens: array of tokens(arguments)
  * @buffer: buffer of command
  * @status: to handle exit status
  * @argv: gets arguments at opening of shell
  * @counter: counts commands entered
 */
typedef struct variables
{
	char **array_tokens;
	char *buffer;
	int status;
	char **argv;
	int counter;
	char **env;
	char **commands;
	char **operator;
	
} vars_t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;


/******Some String operations and manipulation******/
char *_strdup(char *strtodup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
ssize_t _puts(char *str);
int _strlen(char *str);
void print_str(char *str, int new_line);
int _write_char(char c);
int print_number(int n);

/*** BUILTINGS PROTOTYPES ****/
void (*check_for_builtins(vars_t *vars))(vars_t *vars);
void new_exit(vars_t *vars);
void _env(vars_t *vars);
void new_setenv(vars_t *vars);
void new_unsetenv(vars_t *vars);
void new_help(vars_t *vars);


/** functions related to tokenizer **/
char **tokenizer(char *buffer, char *delimiter);
unsigned int check_if_match(char c, const char *str);
char **_realloc(char **ptr, size_t *size);
char *new_strtok(char *str, const char *delim);

/** functions related ask external shell, ask the path**/
void check_for_path(vars_t *vars);

/** function to handle error messages, used to help exit function*/
void _puts_error(char *str);
void prints_error_msg(vars_t *vars, char *msg);
char *integer_converter(unsigned int count);

/** function to help exit builting*/
int _atoi(char *str);

/** functions de help env builting*/
/*this to get enviroment*/
char **make_enviroment(char **env);

/**New_help functions**/
void new_help_exit(vars_t *vars);
void new_help_cd(vars_t *vars);
void new_help_env(vars_t *vars);
void new_help_history(vars_t *vars);
void new_help_unalias(vars_t *vars);
void new_help_unset(vars_t *vars);
void new_help_unsetenv(vars_t *vars);
void new_help_setenv(vars_t *vars);
void new_help_alias(vars_t *vars);
void new_help_else(vars_t *vars);

/** second  tokenizer for && operator*/

unsigned int check_match2(char c, char *str, char *sr, int z);
char *new_strtok2(char *str,  char *delim);
char **tokenizer2(char *buffer, char *delimiter);
#endif /* _SHELL_HOLBERTON_ */
