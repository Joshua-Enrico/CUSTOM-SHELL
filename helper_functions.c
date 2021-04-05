#include "holberton.h"

/**
 * _puts_error - print a string to sdandart error
 * @str: string to print.
 * Return: void
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