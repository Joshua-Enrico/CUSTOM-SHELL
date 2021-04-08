#include "holberton.h"

void new_help10(vars_t *vars)
{
    

    int r;
    char *s;

    UNUSED(vars);

    s = "Argument not found";

    r = _strlen(s);

    r = write(1, s, r);
     _puts_error("\n");
}