#include "monty.h"
/**
 *
 *
 *
 *
 */
void stack_free(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
