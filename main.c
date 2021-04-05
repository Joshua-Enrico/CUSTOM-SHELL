  #include "holberton.h"

int main(int argc __attribute__((unused)), char **argv, char **environment)
{
    size_t len_buffer = 0;
    unsigned int i;

    vars_t vars = {NULL, NULL};

    _puts("$ ");

    while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
   {
     vars.array_tokens = tokenizer(vars.buffer, " ");

      check_for_builtins(&vars);
   }
