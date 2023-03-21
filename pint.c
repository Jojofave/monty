#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: current line number of the Monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{
  if (*stack == NULL)
  {
    fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
    exit(EXIT_FAILURE);
  }

  printf("%d\n", (*stack)->n);
}