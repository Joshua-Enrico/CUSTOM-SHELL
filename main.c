#include "holberton.h"

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **environment __attribute__((unused)))
{
  size_t len_buffer = 0;
 

  vars_t vars = {NULL, NULL};

  puts("$ ");

  while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
  {
    vars.array_tokens = tokenizer(vars.buffer, " ");
    
   
  }
   return (0);
    exit(100);
}