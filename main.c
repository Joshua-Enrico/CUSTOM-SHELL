#include "holberton.h"

int main(int argc __attribute__((unused)), char **argv, char **environment __attribute__((unused)))
{
	size_t len_buffer = 0;
 

	vars_t vars = {NULL, NULL, 0, NULL, 0};

	vars.argv = argv;


	_puts("$ ");

	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.array_tokens = tokenizer(vars.buffer, " ");



		if (check_for_builtins(&vars) == NULL)
		{

		}
		_puts("$ ");
	}


		exit(vars.status);
}
