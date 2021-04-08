#include "holberton.h"

void new_help10(vars_t *vars)
{

    prints_error_msg(vars, ": no help topics match: ");
    _puts_error(vars->array_tokens[1]);
    

    _puts_error(" Try `help help' or `man -k ");
      _puts_error(vars->array_tokens[1]);
      _puts_error("' or `info ");
       _puts_error(vars->array_tokens[1]);
      _puts_error("'.");


    _puts_error("\n");
    return;
}