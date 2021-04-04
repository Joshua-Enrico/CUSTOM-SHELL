#include "holberton.h"
#define SHELLNAME "Mishell $ "

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
        char *line;
        size_t len_buffer;
        ssize_t read_len;

        do {
                line = NULL;
                len_buffer = 0;
                write(STDOUT_FILENO, SHELLNAME, str_len(SHELLNAME));
                read_len = getline(&line, &len_buffer, stdin);
        } while (1);

        return (0);
}
