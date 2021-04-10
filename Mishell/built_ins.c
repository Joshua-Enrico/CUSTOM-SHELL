#include "holberton.h"

/**
 * built_in - Checks for builtin functions.
 * @vars: A string representing the input from the user.
 * Return: If function is found 0. Otherwise -1.
 */
int built_in(vars_t vars)
{
	void (*build)(vars_t);
	int i;

	build = check_built_ins(vars);
	if (build == NULL)
		return (-1);
	if (_strcmp("exit", vars.array_tokens[0]) == 0)
	{
		for (i = 0; vars.array_tokens[i] != NULL; i++)
			free(vars.array_tokens[i]);
		free(vars.array_tokens);
	}
	build(vars);
	return (0);
}

/**
 * check_built_ins - Finds the right function needed for execution.
 * @vars: The name of the function that is needed.
 * Return: Upon sucess a pointer to a void function. Otherwise NULL.
 */
void (*check_built_ins(vars_t vars))(vars_t vars)
{
	int i;

	builtins_t check[] = {
		{"exit", exit_b},
		{"env", env_b},
		{"cd", cd_b},
		{NULL, NULL}
	};

	for (i = 0; check[i].name != NULL; i++)
	{
		if (_strcmp(vars.array_tokens[0], check[i].name) == 0)
		{
			return (check[i].f);
		}
	}
	return (NULL);
}

/**
 * exit_b - Exits the shell. After freeing allocated resources.
 * @vars: A string representing the input from the user.
 */
void exit_b(vars_t vars)
{
	free(vars.buffer);
	print_str("\n", 1);
	exit(1);
}

/**
 * env_b - Prints all the environmental variables in the current shell.
 * @vars: A string representing the input from the user.
 */
void env_b(__attribute__((unused))vars_t vars)
{
	int i;
	int j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * cd_b - Changes the current working directory to the parameter passed to cd.
 * if no parameter is passed it will change directory to HOME.
 * @vars: A string representing the input from the user.
 */
void cd_b(vars_t vars)
{
	int index, i;
	int token_count;
	const char *delim = "\n\t ";

	token_count = 0;
	vars.array_tokens = token_interface(vars.buffer, delim, token_count);
	if (vars.array_tokens[0] == NULL)
	{
		free(vars.array_tokens);
		free(vars.buffer);
		return;
	}
	if (vars.array_tokens[1] == NULL)
	{
		index = find_env_index("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(vars.array_tokens[1], "-") == 0)
		print_str(vars.array_tokens[1], 0);

	else
		chdir(vars.array_tokens[1]);
	for (i = 0; vars.array_tokens[i] != NULL; i++)
		free(vars.array_tokens[i]);
	free(vars.array_tokens);
}
