#include "holberton.h"

/**
 * tokenize - tokenizes a buffer with a delimiter
 * @buffer: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenizer2(char *buffer, char *delimiter)
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
	while ((tokens[i] = new_strtok2(buffer, delimiter)) != NULL)
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

/**
 * new_strtok - custom strtok
 * @str: string to tokenize
 * @delim: delimiter to tokenize against
 *
 * Return: pointer to the next token or NULL
 */
char *new_strtok2(char *str,  char *delim)
{
    static char *token_start;
    static char *next_token;
    unsigned int i;
    

    if (str != NULL)
        next_token = str;
    token_start = next_token;
    if (token_start == NULL)
        return (NULL);
    for (i = 0; next_token[i] != '\0'; i++)
    {
        if (check_if_match(next_token[i], delim) == 0)
            break;
    }
    if (next_token[i] == '\0' || next_token[i] == '#')
    {
        next_token = NULL;
        return (NULL);
    }
    token_start = next_token + i;
    next_token = token_start;
    for (i = 0; next_token[i] != '\0'; i++)
    {
     
        if (check_match2(next_token[i], delim, next_token, i) == 1)
        {

            break;
        }
    }
    if (next_token[i] == '\0')
        next_token = NULL;
    else
    {
        next_token[i] = '\0';
        next_token = next_token + i + 2;
        if (*next_token == '\0')
            next_token = NULL;
    }
    return (token_start);
}

unsigned int check_match2(char c, char *str, char *sr, int z)
{
    unsigned int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (c == str[i])
           i++;
           z++;
            if (c == str[i])
            {
             
             
              sr[z] = '\0';
              
             
              return (1);
            }
    }
    return (0);
}