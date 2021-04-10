#include "holberton.h"

/**
 * tokenize - tokenizes a buffer with a delimiter
 * @buffer: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenizer(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0, mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = new_strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == mcount)
		{
			tokens = _realloc(tokens, &mcount);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}




char **tokenize(int token_count, char *line, const char *delimiter)
{
	int i;
	char **buffer;
	char *token;
	char *line_cp;

	line_cp = _strdup(line);
	buffer = malloc(sizeof(char *) * (token_count + 1));
	if (buffer == NULL)
		return (NULL);
	token = new_strtok(line_cp, delimiter);
	for (i = 0; token != NULL; i++)
	{
		buffer [i] = _strdup(token);
		token = new_strtok(NULL, delimiter);
	}
	buffer[i] = NULL;
	free(line_cp);
	return (buffer);
}

char **token_interface(char *line, const char *delimiter, int token_count)
{
	vars_t vars;

	token_count = count_token(line, delimiter);
	if (token_count == -1)
	{
		free(line);
		return (NULL);
	}
	vars.array_tokens = tokenize(token_count, line, delimiter);
	if (vars.array_tokens == NULL)
	{
		free(line);
		return (NULL);
	}

	return(vars.array_tokens);
}

int count_token(char *line, const char *delimiter)
{
	char *str;
	char *token;
	int i;

	str = _strdup(line);
	if (str == NULL)
		return (-1);
	token = new_strtok(str, delimiter);
	for (i = 0; token != NULL; i++)
		token = new_strtok(NULL, delimiter);
	free(str);
	return (i);
}
