#include "holberton.h"

void new_help(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;
	if (vars->array_tokens[1] == NULL)
	{
		file = "helpfiles/help";
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
		return;
	}

	else if (_strcmpr(vars->array_tokens[1], "help") == 0)
	{
		file = "helpfiles/help_help";
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
		new_help_exit(vars);
}
void new_help_exit(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "exit") == 0)
	{
		file = "helpfiles/exit";
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
		new_help_cd(vars);
}

void new_help_cd(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "cd") == 0)
	{
		file = "helpfiles/cd";
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
		new_help_env(vars);
}
void new_help_env(vars_t *vars)
{
	char *file;
	int fd, r;
	char *s;

	if (_strcmpr(vars->array_tokens[1], "env") == 0)
	{
		file = "helpfiles/env";
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
		new_help_history(vars);
}
