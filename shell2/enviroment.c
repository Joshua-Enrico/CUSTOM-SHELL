#include "holberton.h"

char **make_enviroment(char **env)
{
char **newenviroment = NULL;

unsigned long i;

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