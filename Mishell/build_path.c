#include "holberton.h"

/**
 * build_path - Combines two strings one representing the path directory and
 * another representing the command file.
 * @directory: Represents a directory in the path.
 * @command: Represents a file in a directory of the path.
 * Return: Upon success a string representing the full path of a command.
 * Otherwise NULL.
 */
char *build_path(char *directory, char *command)
{
	int i, j;
	int dir_len;
	int command_len;
	int len;
	char *built;

	if (directory == NULL || command == NULL)
		return (NULL);
	dir_len = str_len(directory) + 1;
	command_len = str_len(command) + 1;
	len = dir_len + command_len;

	built = malloc(sizeof(char) * len);
	if (built == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		for (j = 0; directory[j] != '\0'; j++, i++)
			built[i] = directory[j];
		built[i] = '/';
		i++;
		for (j = 0; command[j] != '\0'; j++, i++)
			built[i] = command[j];
	}
	built[--i] = '\0';
	return (built);
}
