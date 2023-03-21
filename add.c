#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: current line number of the Monty file
 */
void add(stack_t **stack, unsigned int line_number)
{
  int sum;

  if (*stack == NULL || (*stack)->next == NULL)
  {
    fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
    exit(EXIT_FAILURE);
  }

  sum = (*stack)->n + (*stack)->next->n;
  (*stack)->next->n = sum;
  pop(stack, line_number);
}
