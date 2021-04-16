#include "holberton.h"

/*** WRITES STRING TO STDOUT ***/
/**
 * _puts3 - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t _puts3(char *str)
{
	ssize_t i, len;

	for (i = 0; str[i]; i++)
		;

	len = write(1, str, i);
	if (len != i)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
/**
 *print_message - print a string to standart output
 * @str: string to print.
 * Return: void
 */
void print_message(char *str)
{
	long num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)

	{
		perror("fatal error");
		exit(1);
	}
}

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print
 */

void read_textfile(vars_t *vars)
{
	char *file;
	int fd, r;

	char *s, *z;
	int i = 0;
	int x = 0;
	if (vars->array_tokens[1] == NULL)
	{
		file = ".simple_shell_history";
		fd = open(file, O_RDWR);

		s = malloc(4096);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 4096)) > 0)
		{
			z = s;
			_putchar('0');
			_putchar(' ');
			_putchar(' ');
			while (*z)
			{
				if (*z == '\n')
				{
					i++;	
				}
				z++;
			}
			i--;
			z = s;
			while (*z)
			{
				_putchar(*z);
				if (*z == '\n' && x < i)
				{
					x++;
					if (x == i)
					break;
					else
					integer_converter2(x);
					_putchar(' ');
					_putchar(' ');	
				}
				z++;
			}
			if (r == -1)
			{
				_puts_error("Fatal Error");
				return;
			}
		}
		free(s);
		fd = close(fd);
		return;
	}
	else
		new_help_help(vars);
}

/**
 * append_text_to_file - appends a text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(vars_t *vars)
{
	int ft;
	long _write;
	char *compare = vars->buffer;

	const char *filename = ".simple_shell_history";

	if (_strcmpr(vars->buffer, "\n") == 0)
	{
		return (0);
	}

	if (_strcmpr2(compare) == 0)
	{
		return (0);
	}

	if (filename == NULL)
	{
		return (-1);
	}

	ft = open(filename, O_RDWR | O_APPEND);

	if (ft == -1)
	{
		close(ft);
		return (-1);
	}
	if (vars->buffer != NULL)
	{
		_write = write(ft, vars->buffer, _strlen(vars->buffer));
	}
	close(ft);

	if (_write == -1)
	{
		return (-1);
	}
	return (1);
}

int _strcmpr2(char *strcmp1)
{
	int i;

	i = 0;
	while (strcmp1[i] != '\0')
	{
		if (strcmp1[0] == ' ')
			return (0);
		if (strcmp1[1] != ' ')
			return (1);
		if (strcmp1[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}
/**
 *print_message - print a string to standart output
 * @str: string to print.
 * Return: void
 */
void print_message1(char *str)
{
	long num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)

	{
		perror("fatal error");
		exit(1);
	}
}

void _putchar(char c)
{
	write(1, &c, 1);
	return;
}

char *integer_converter2(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;

	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;

	numstr = malloc(sizeof(char) * (digits + 1));

	if (numstr == NULL)
	{
		perror("Fatal Error");
		exit(100);
	}

	numstr[digits] = '\0';

	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	print_message(numstr);
	return (0);
}