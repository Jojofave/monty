#include "monty.h"

/* create a new stack */
stack_t *create_stack(void)
{
    return NULL;
}

/* push a new value onto the stack */
void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

/* print all values on the stack */
void pall(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/* free all nodes in the stack */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        stack_t *next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}
