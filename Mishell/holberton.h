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

/**** Estructura con las posibles variables que vamos a usar ****/
/**
 * struct variables - variables
 * @av: command line arguments
 * @buffer: buffer of command
 */
typedef struct variables
{
	char **array_tokens;
	char *buffer;
} vars_t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
        char *name;
        void (*f)(vars_t );
} builtins_t;

/******Some String operations and manipulation******/
char *_strdup(char *strtodup);
int _strcmp(char *s1, char *s2);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
ssize_t _puts(char *str);
int str_len(char *str);
void print_str(char *str, int new_line);
int _write_char(char c);
int print_number(int n);

/* TOKEN FUNCTIONS */
void parse_line(vars_t vars, size_t len_buffer, int command_counter, char **av);
char **token_interface(char *line, const char *delimiter, int token_count);
int count_token(char *line, const char *delimiter);
char **tokenize(int token_count, char *line, const char *delimiter);

/* CHILD FUNCTIONS */
char *build_path(char *directory, char *command);
void fork_child(vars_t vars, int count, char **av);
char *path_finder(char *command);
int find_env_index(char *str);
char **tokenize_path(int index, char *str);
char *search_directories(char **path_tokens, char *command);

/* BUILT_IN FUNCTIONS */
int built_in(vars_t vars);
void (*check_built_ins(vars_t vars))(vars_t vars);
void exit_b(vars_t vars);
void env_b(vars_t vars);
void cd_b(vars_t vars);

void error_printing(char *av, int count, char *command);
extern char **environ;
void exec_error(char *av, int count, char *tmp_command);

#endif /* _SHELL_HOLBERTON_ */
