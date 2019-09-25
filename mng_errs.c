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
		"Error: malloc failed\n",
		"USAGE: monty file\n",
		"usage: push integer\n",
		"can't pint, stack empty",
		"can't pop an empty stack",
		"can't swap, stack too short",
		"can't add, stack too short",
		"can't sub, stack too short"
	};
	if (T)
		n = T->ln;
	if (e <= 1)
		dprintf(STDOUT_FILENO, "%s", errs[e]);
	else if (e == 2)
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", T->fname);
	else if (e == 3)
		dprintf(STDOUT_FILENO, "L%u: unknown instrunction %s\n",
			n, T->toks[0]);
	else if (e >= 4)
		dprintf(STDOUT_FILENO, "L%u: %s\n", n, errs[e]);
	free_all();
	exit(EXIT_FAILURE);
}
