#include "holberton.h"
/**
 * new_cd - Changes the c.working directory to the parameter passed to cd.
 * if no parameter is passed it will change directory to HOME.
 * @vars: A string representing the input from the user.
 */
void new_cd(vars_t *vars)
{
	char **dir_info;
	char *oldpwd = NULL, *pwd = NULL, *new_line = "\n";
	int index;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (oldpwd == NULL)
	{
		perror("Fatal Error");
		exit(100);
	}

	if (vars->array_tokens[1])
	{
		if (*(vars->array_tokens[1]) == '-' ||
		    (_strcmpr(vars->array_tokens[1], "--") == 0))
		{
			if ((vars->array_tokens[1][1] == '-' &&
			     vars->array_tokens[1][2] == '\0') ||
			    vars->array_tokens[1][1] == '\0')
			{
				index = find_env_index(*vars, "OLDPWD");
				if (index < 0)
					return;
				chdir((vars->env[index]) + 7);
			}
			else
			{
				free(oldpwd);
				print_str("-bash: cd: ", 1);
				print_str(vars->array_tokens[1], 1);
				print_str(": invalid option", 0);
				print_str("cd: usage: cd [-] [--]", 0);
				return;
			}
		}
		else
		{
			if (stat(vars->array_tokens[1], &dir) == 0 &&
		    S_ISDIR(dir.st_mode) && ((dir.st_mode & S_IXUSR) != 0))
				chdir(vars->array_tokens[1]);
			else
			{
				free(oldpwd);
				print_str("-bash: cd: ", 1);
				print_str(vars->array_tokens[1], 1);
				print_str(": Not a directory", 0);
				return;
			}
		}
	}
	else
	{
		index = find_env_index(*vars, "HOME");
		if (index < 0)
			return;
		chdir((vars->env[index]) + 5);
	}

	pwd = getcwd(pwd, 0);
	if (!pwd)
	{
		perror("Fatal Error");
		exit(100);
	}

	dir_info = malloc(sizeof(char *) * 2);
	if (!dir_info)
	{
		perror("Fatal Error");
		exit(100);
	}

	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	setenv_cd(dir_info, vars);

	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	setenv_cd(dir_info, vars);

	if (vars->array_tokens[1] && vars->array_tokens[1][0] == '-' &&
				       vars->array_tokens[1][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, new_line, 1);
	}
	free(oldpwd);
	free(pwd);
	free(dir_info);
}

/**
 * setenv_cd - create a new environment variable, or edit an existing variable
 * @vars: pointer to struct of variables
 *
 * Return: void
 */
void setenv_cd(char **args, vars_t *vars)
{
	char **key;
	char *var;

	if (args[0] == NULL ||  args[1] == NULL)
	{
		prints_error_msg(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}
	key = find_key(vars->env, args[0]);
	if (key == NULL)
	{
		add_key(vars);
	}
	else
	{
		var = add_value(args[0], args[1]);
		if (var == NULL)
		{
			prints_error_msg(vars, NULL);
			free(vars->buffer);
			free(args);
			free(vars->commands);
			free_env(vars->env);
			exit(127);
		}
		free(*key);
		*key = var;
	}
	vars->status = 0;
}
