#include "holberton.h"

int main(int argc __attribute__((unused)), char **argv, char **environment __attribute__((unused)))
{
	size_t len_buffer = 0;

	vars_t vars = {NULL, NULL, 0, NULL, 0};

	vars.argv = argv;

	_puts("$ ");

	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.counter++;
		vars.array_tokens = tokenizer(vars.buffer, " \t\r\n\a");

		if (vars.array_tokens && vars.array_tokens[0])
			if (check_for_builtins(&vars) == NULL)
		

		free(vars.buffer);
		_puts("$ ");
		vars.buffer = NULL;
	}

	exit(vars.status);
}
