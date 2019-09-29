#include "monty.h"
/**
 * mng_errs - function to manage the errors
 * @e: The error number
 *
 * Return: void
 */
void mng_errs(int e)
{
	unsigned int n;
	static char *const errs[] = {
		"Error: malloc failed",
		"USAGE: monty file",
		"", "", "usage: push integer",
		"can't pint, stack empty",
		"can't pop an empty stack",
		"can't swap, stack too short",
		"can't add, stack too short",
		"can't sub, stack too short",
		"can't div, stack too short",
		"division by zero",
		"can't mul, stack too short",
		"can't mod, stack too short",
		"can't pchar, stack empty",
		"can't pchar, value out of range"
	};
	if (T)
		n = T->ln;
	if (e <= 1)
		fprintf(stderr, "%s\n", errs[e]);
	else if (e == 2)
		fprintf(stderr, "Error: Can't open file %s\n", T->fname);
	else if (e == 3)
		fprintf(stderr, "L%u: unknown instruction %s\n",
			n, T->toks[0]);
	else if (e >= 4)
		fprintf(stderr, "L%u: %s\n", n, errs[e]);
	free_all();
	exit(EXIT_FAILURE);
}
