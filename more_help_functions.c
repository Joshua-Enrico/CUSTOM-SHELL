#include "holberton.h"
/**
 * new_help_history - help builtin command history
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_history(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "history") == 0)
	{
		file = "helpfiles/history";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			_puts_error("\n");
			if (r == -1)
			{
				
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		new_help_unalias(vars);
}
/**
 * new_help_unalias - help builtin command unalias
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_unalias(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "unalias") == 0)
	{
		file = "helpfiles/unalias";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			_puts_error("\n");
			if (r == -1)
			{
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		new_help_unset(vars);
}
/**
 * new_help_unset - help builtin command unset
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_unset(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "unset") == 0)
	{
		file = "helpfiles/unset";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			_puts_error("\n");
			if (r == -1)
			{
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		new_help_unsetenv(vars);
}
/**
 * new_help_unsetenv - help builtin command unsetenv
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_unsetenv(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "unsetenv") == 0)
	{
		file = "helpfiles/unsetenv";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			_puts_error("\n");
			if (r == -1)
			{
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		new_help_setenv(vars);
}
/**
 * new_help_setenv - help builtin command setenv
 * @vars: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
void new_help_setenv(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "setenv") == 0)
	{
		file = "helpfiles/setenv";
		fd = open(file, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
		}
		while ((r = read(fd, s, 300)) > 0)
		{
			r = write(1, s, r);
			_puts_error("\n");
			if (r == -1)
			{
			}
		}
		free(s);
		fd = close(fd);
	}
	else
		new_help_alias(vars);
}
