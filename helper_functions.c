#include "holberton.h"

/**
 * _puts_error
 * 
 * 
 * 
 */

void _puts_error(char *str)
{
    long num, len;

    num = _strlen(str);
    len = write(STDERR_FILENO, str, num);
    if (len != num)

    {
        perror ("fatal error");
        exit(0);
    }
}