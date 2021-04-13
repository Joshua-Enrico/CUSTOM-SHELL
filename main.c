#include "holberton.h"

unsigned int sig_flag;

static void sig_handler(int uuv)
{
	(void)uuv;
	if (sig_flag == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}

int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int i;

	vars_t vars = {NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL};

	vars.argv = argv;
	vars.env = environment;

	signal(SIGINT, sig_handler);
	/** necesitare una funcion para obtener el entorno de "enviroment esto"
para el bulting "env" */

	_puts("$ ");

	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.counter++;

		add_nodeint(&vars.head, vars.buffer);
		vars.history = vars.head;

		vars.commands = tokenizer(vars.buffer, ";");

		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.array_tokens = tokenizer(vars.commands[i], " \t\r\n\a");
			if (vars.array_tokens && vars.array_tokens[0])
				if (check_for_builtins(&vars) == NULL)
				{
					fork_child(vars);
				}
			free(vars.array_tokens);
		}
		free(vars.buffer);
		free(vars.commands);
		
		_puts("$ ");
		vars.buffer = NULL;
	}

	exit(vars.status);
}
