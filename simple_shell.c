#include "holberton.h"

/**
 * sig_handler - handles ^C signal interupt
 * @unused: unused variable (required for signal function prototype)
 *
 * Return: void
 */
static void sig_handler(int unused)
{
	(void)unused;
	if (sig_flag == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}

/**
 * main - main function for the shell
 * @argc: number of arguments passed to main, unused
 * @argv: array of arguments passed to main
 * @environment: array of environment variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int i;

	vars_t vars = {NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL};

	vars.argv = argv;
	vars.env = make_enviroment(environment);

	signal(SIGINT, sig_handler);
	_puts("$ ");

	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.counter++;

		add_nodeint(&vars.history, vars.buffer);

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
