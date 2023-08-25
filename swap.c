#include "monty.h"
/**
 *
 *
 *
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
	{
		temp->next->prev = (*stack)->next;
	}
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
