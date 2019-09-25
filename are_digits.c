#include "monty.h"
/**
 * are_digits - verify if the string is a number
 * @s: The string to verify
 * Return: 1 or 0
 */
int are_digits(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-' && i == 0)
			i++;
		if (isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}
