#include "holberton.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void *check_for_builtins(vars_t *vars)
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
		;
	{
		status = _atoi(vars->array_tokens[1]);
		if (status == -1)
		{
			vars->status = 2;
			/** aqui necesitamos una funcion para imprimir un mensaje de error */
			/** aqui una funcion para imprimir error hacia stderr error*/
			/* seguramente necesitamosun salto de linea , a probar*/
			/* uso de la funcion free cuando de necesita */
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
}
void new_setenv(vars_t *vars)
{
}
void new_unsetenv(vars_t *vars)
{
}