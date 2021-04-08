#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>


int _strcmpr(char *strcmp1, char *strcmp2);
void _puts2(char *str);
int _atoi(char *str);
unsigned int _strlen(char *str);
char *_uitoa(unsigned int count);
int main(void)

{
  char *s = "exit";
  char *c = "-1";
  int commands = 0;
    int status;
    int status1;

    if (_strcmpr(s, "exit") == 0 && c != NULL)
    {
        status = _atoi(c);
        if (status == -1)
        {
            status1 = 2;
            print_error("hola", ": Illegal number: ");
            _puts2(c);
            _puts2("\n");
           
            commands = NULL;
            return;
        }
        status1 = status;
    }
    
    exit(status1);
}


int _strcmpr(char *strcmp1, char *strcmp2)
{
    int i;

    i = 0;
    while (strcmp1[i] == strcmp2[i])
    {
        if (strcmp1[i] == '\0')
            return (0);
        i++;
    }
    return (strcmp1[i] - strcmp2[i]);
}

int _atoi(char *str)
{
    unsigned int i, digits;
    int num = 0, num_test;

    num_test = INT_MAX;
    for (digits = 0; num_test != 0; digits++)
        num_test /= 10;
    for (i = 0; str[i] != '\0' && i < digits; i++)
    {
        num *= 10;
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        if ((i == digits - 1) && (str[i] - '0' > INT_MAX % 10))
            return (-1);
        num += str[i] - '0';
        if ((i == digits - 2) && (str[i + 1] != '\0') && (num > INT_MAX / 10))
            return (-1);
    }
    if (i > digits)
        return (-1);
    return (num);
}
void _puts2(char *str)
{
    ssize_t num, len;

    num = _strlen(str);
    len = write(STDERR_FILENO, str, num);
    if (len != num)
    {
        perror("Fatal Error");
        exit(1);
    }

}


void print_error(char *vars, char *msg)
{
    char *count;
    int S = 1;
    char *z = "hola";
    char *av = "exit";
    
    _puts2(z);
    _puts2(": ");
    count = _uitoa(S);
    _puts2(count);
    free(count);
    _puts2(": ");
    _puts2(av);
    if (msg)
    {
        _puts2(msg);
    }
    else
        perror("");
        
}

unsigned int _strlen(char *str)
{
    unsigned int len;

    len = 0;

    for (len = 0; str[len]; len++)
        ;
    return (len);
}
char *_uitoa(unsigned int count)
{
    char *numstr;
    unsigned int tmp, digits;

    tmp = count;
    for (digits = 0; tmp != 0; digits++)
        tmp /= 10;
    numstr = malloc(sizeof(char) * (digits + 1));
    if (numstr == NULL)
    {
        perror("Fatal Error1");
        exit(127);
    }
    numstr[digits] = '\0';
    for (--digits; count; --digits)
    {
        numstr[digits] = (count % 10) + '0';
        count /= 10;
    }
    return (numstr);
}
