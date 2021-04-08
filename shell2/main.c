#include "holberton.h"

unsigned int sig_flag;


static void sig_handler(int uuv)
{
	(void) uuv;
	if (sig_flag == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}



int main(int argc __attribute__((unused)), char **argv, char **environment )
{
	size_t len_buffer = 0;

	vars_t vars = {NULL, NULL, 0, NULL, 0, NULL};

	vars.argv = argv;
	vars.env = environment;
	 signal(SIGINT, sig_handler);
/** necesitare una funcion para obtener el entorno de "enviroment esto"
para el bulting "env" */
	

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
