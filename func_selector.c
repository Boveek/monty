#include "monty.h"
/**
 *
 *
 *
 *
 */
void (*func_select(char *opcode))(stack_t **, unsigned int)
{
	int i;

	instruction_t my_array[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	for (i = 0; my_array[i].opcode; i++)
	{
		if (strcmp(opcode, my_array[i].opcode) == 0)
		{
			return (my_array[i].f);
		}
	}
	return (NULL);
}
