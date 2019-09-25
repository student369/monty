#include "monty.h"
/**
 * tok_line - parse the line given
 * @line: the line
 *
 * Return: EXIT_SUCCESS
 */
int tok_line(char *line)
{
	char *delim, *s;
	int len, i;

	delim = TOK_DELIM;
	s = T->line;
	len = strlen(s);
	for (i = 0; s[i] == delim[0] || s[i] == delim[1]; i++)
		;
	if (i == len)
		return (EXIT_FAILURE);
	T->toks[0] = strtok(line, delim);
	T->toks[1] = strtok(NULL, delim);
	return (EXIT_SUCCESS);
}
