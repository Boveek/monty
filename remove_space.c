#include "monty.h"
/**
 *
 *
 *
 */
void removeExtraSpaces(char *str)
{
	int i, j;
	int len = strlen(str);
	
	for (i = 0, j = 0; i < len; i++)
	{
		if (str[i] == ' ' && (i == 0 || str[i - 1] == ' '))
		{
			continue;
		}
		str[j++] = str[i];
	}
	str[j] = '\0';
}
