#include "monty.h"
/**
 *
 *
 *
 *
 */
int ini_stack(stack_t **stack)
{
	stack_t *nw;

	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	nw->n = 0;
	nw->prev = NULL;
	nw->next = NULL;

	*stack = nw;
	return (EXIT_SUCCESS);
}
