#include "holberton.h"

/**
 * new_cd - Changes the current working directory to the parameter passed to cd.
 * if no parameter is passed it will change directory to HOME.
 * @vars: A string representing the input from the user.
 */
void new_cd(vars_t *vars)
{
	int index, i;
	const char *delim = "\n\t ";

	
	vars->array_tokens = token_interface(vars->buffer, delim, vars->counter);
	if (vars->array_tokens[0] == NULL)
	{
		free(vars->array_tokens);
		free(vars->buffer);
		return;
	}
	if (vars->array_tokens[1] == NULL)
	{
		index = find_env_index(*vars, "HOME");
		chdir((vars->env[index]) + 5);
	}
	else if (_strcmpr(vars->array_tokens[1], "-") == 0)
		print_str(vars->array_tokens[1], 0);

	else
		chdir(vars->array_tokens[1]);
	for (i = 0; vars->array_tokens[i] != NULL; i++)
		free(vars->array_tokens[i]);

}
