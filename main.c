  #include "holberton.h"

int main ()
{
    size_t len_buffer = 0;

    vars_t vars = {NULL, NULL};

    _puts("$ ");

    while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
    {
        

    }
}