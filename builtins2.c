#include "holberton.h"
#define TINY vars->array_tokens
#define ST dir.st_mode

/**
 * new_cd - Changes the c.working directory to the parameter passed to cd.
 * if no parameter is passed it will change directory to HOME.
 * @vars: A string representing the input from the user.
 */
void new_cd(vars_t *vars)
{
	char **dir_info, *oldpwd = NULL, *pwd = NULL;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (oldpwd == NULL)
		simple_error();
	if (TINY[1])
	{
		if (*(TINY[1]) == '-' || (_strcmpr(TINY[1], "--") == 0))
		{
			if ((TINY[1][1] == '-' && TINY[1][2] == '\0') || TINY[1][1] == '\0')
				chdir_to_env(vars, "OLDPWD");
			else
				print_cd_1(vars);
		} else
		{
			if (stat(TINY[1], &dir) == 0 && S_ISDIR(ST) && ((ST & S_IXUSR) != 0))
				chdir(TINY[1]);
			else
				print_cd_2(vars);
		}
	} else
		chdir_to_env(vars, "HOME");
	pwd = getcwd(pwd, 0);
	if (!pwd)
		simple_error();
	dir_info = malloc(sizeof(char *) * 2);
	if (!dir_info)
		simple_error();
	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	setenv_cd(dir_info, vars);
	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	setenv_cd(dir_info, vars);
	if (TINY[1] && TINY[1][0] == '-' && TINY[1][1] == '\0')
		print_str(pwd, 0);
	free(oldpwd);
	free(pwd);
	free(dir_info);
}

/**
 * setenv_cd - create a new environment variable, or edit an existing variable
 * @vars: pointer to struct of variables
 * @args: arguments to pass.
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
