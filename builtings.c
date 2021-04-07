#include "holberton.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*check_for_builtins(vars_t *vars))(vars_t *vars)
{
	unsigned int i;
	builtins_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{NULL, NULL}};

	for (i = 0; check[i].f != NULL; i++)
	{
		/** vars->av esta accediendo a los argumentos posiblemente se va a modificar*/
		if (_strcmpr(vars->array_tokens[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
		check[i].f(vars);
	return (check[i].f);
}

void new_exit(vars_t *vars)
{
	int status;
	if (_strcmpr(vars->array_tokens[0], "exit") == 0 && vars->array_tokens[1] != NULL)
		
	{
		/* con esta funcion nos aseguramos que el numero ingresad sea valido*/
		status = _atoi(vars->array_tokens[1]);
		/* si no lo es , manejaremos el caso de error personalizado imprimiendo un error con su mensaje*/
		if (status == -1)
		{
			vars->status = 2;
			/*imprimira un mensaje de error */
			prints_error_msg(vars, ": Illegal number: ");
			_puts_error(vars->array_tokens[1]);
			_puts_error("\n");
			return;
		}
		vars->status = status;
	}
	free(vars->array_tokens);
	free(vars->buffer);
	exit(vars->status);
}
void _env(vars_t *vars)
{
	UNUSED(vars);
}
void new_setenv(vars_t *vars)
{
	UNUSED(vars);
}
void new_unsetenv(vars_t *vars)
{
	UNUSED(vars);
}