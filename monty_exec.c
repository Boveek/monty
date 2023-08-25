#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
char **token = NULL;
/**
 *
 *
 *
 *
 */
int main(int argc, char *argv[])
{
	char line_input[MAX_LINE_LENGTH];
	FILE *arg_file;
	void (*opcode_func)(stack_t **, unsigned int);
	size_t len;
	stack_t *new = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	arg_file = fopen(argv[1], "r");
	if (arg_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (ini_stack(&new) == EXIT_FAILURE)
	{
		stack_free(&new);
		return (EXIT_FAILURE);
	}
	while (fgets(line_input, sizeof(line_input), arg_file) != NULL)
	{
		counter++;
		len = strlen(line_input);
		if (len > 0 && line_input[len - 1] == '\n')
		{
			line_input[len - 1] = '\0';
		}
		removeExtraSpaces(line_input);
		token = tokenize(line_input);
		opcode_func = func_select(token[0]);
		if (opcode_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", counter, token[0]);
			stack_free(&new);
			free_token();
			exit(EXIT_FAILURE);
		}
		opcode_func(&new, counter);
		memset(line_input, 0, sizeof(line_input));
		free_token();
	}
	stack_free(&new);
	fclose(arg_file);
	return (0);
}
