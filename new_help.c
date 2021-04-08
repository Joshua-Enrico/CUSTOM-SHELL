#include "holberton.h"

void new_help(vars_t *vars)
{
    char *file;
    int fd, r;
    char *s;

    if (_strcmpr(vars->array_tokens[1], "l") == 0)
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
    }
	free(vars->commands);
	free(vars->array_tokens);
	free(vars->buffer);
	exit(vars->status);
}