#include "holberton.h"

void new_help5(vars_t *vars)
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
    new_help6(vars);
}

void new_help6(vars_t *vars)
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
    new_help7(vars);
}

void new_help7(vars_t *vars)
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
    new_help8(vars);
}

void new_help8(vars_t *vars)
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
    new_help9(vars);
}

void new_help9(vars_t *vars)

{
    char *file;
    int fd, r;
    char *s;

    if (_strcmpr(vars->array_tokens[1], "alias") == 0)
    {
        file = "helpfiles/alias";
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
}