#include "holberton.h"

char **make_enviroment(char **env)
{
char **newenviroment = NULL;

size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenviroment = malloc(sizeof(char *) * (i + 1));
	if (newenviroment == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenviroment[i] = _strdup(env[i]);
	newenviroment[i] = NULL;
	return (newenviroment);
}

/**
 * free_env - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void free_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}