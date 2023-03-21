#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: current line number of the Monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;

  if (*stack == NULL || (*stack)->next == NULL)
  {
    fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
    exit(EXIT_FAILURE);
  }

  temp = (*stack)->next;
  (*stack)->next = temp->next;
  if (temp->next != NULL)
    temp->next->prev = *stack;
  temp->next = *stack;
  temp->prev = (*stack)->prev;
  (*stack)->prev = temp;
  *stack = temp;
}
