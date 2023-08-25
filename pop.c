#include "monty.h"
/**
 *
 *
 *
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
	{
		next->prev = *stack;
	}
	(*stack)->next = next;
}
