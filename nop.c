#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * nop - does nothing
 * @stack: double pointer to the top of the stack
 * @line_number: current line number of the Monty file
 */
void nop(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
}
