#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: current line number of the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
  char *arg;
  int n;
  stack_t *new;

  arg = strtok(NULL, " \n");
  {
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
  }

  n = atoi(arg);
  new = malloc(sizeof(stack_t));
  if (new == NULL)
  {
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }

  new->n = n;
  new->prev = NULL;
  if (*stack == NULL)
    new->next = NULL;
  else
  {
    new->next = *stack;
    (*stack)->prev = new;
  }
  *stack = new;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number of the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;

  (void)line_number;
  temp = *stack;
  while (temp != NULL)
  {
    printf("%d\n", temp->n);
    temp = temp->next;
  }
}
