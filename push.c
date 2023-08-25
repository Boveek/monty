#include "monty.h"
/**
 *
 *
 *
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (token[1] == NULL || atoi(token[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(token[1]);
	temp = (*stack)->next;
	new->prev = *stack;
	new->next = temp;
	if (temp)
		temp->prev = new;
	(*stack)->next = new;

}

