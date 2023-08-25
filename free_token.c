#include "monty.h"
/**
 *
 *
 *
 *
 */
void free_token(void)
{
	size_t j = 0;

	for (j = 0; token[j]; j++)
	{
		free(token[j]);
	}
	free(token);
}
