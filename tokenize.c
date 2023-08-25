#include "monty.h"
#include <string.h>
/**
 *
 *
 *
 */
char **tokenize(char *input)
{
	char *tokenise, *input_copy, **tk;
	int num_token = 0, i;

	input_copy = malloc(strlen(input) + 1);
	if (input_copy == NULL)
	{
		free(input_copy);
		return (NULL);
	}
	strcpy(input_copy, input);
	tokenise = strtok(input, " ");
	if (tokenise == NULL)
	{
		free(input_copy);
		return (NULL);
	}
	while (tokenise != NULL)
	{
		num_token++;
		tokenise = strtok(NULL, " ");
	}
	num_token++;
	tk = malloc(sizeof(char *) * num_token);
	if (tk == NULL)
	{
		free(tk);
		return(NULL);
	}
	tokenise = strtok(input_copy, " ");
	for (i = 0; tokenise != NULL; i++)
	{
		tk[i] = malloc(sizeof(char) * (strlen(tokenise) + 1));
		if (tk[i] == NULL)
		{
			free(tk[i]);
			return (NULL);
		}
		strcpy(tk[i], tokenise);
		tokenise = strtok(NULL, " ");
	}
	tk[i] = NULL;
	free(input_copy);
	return (tk);
}
