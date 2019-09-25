#include "monty.h"

/**
 * build_things - Function to init the global structure T.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int build_things(void)
{
	T = (things_t *)malloc(sizeof(things_t));
	if (!T)
		mng_errs(ERROR_MALLOC);
	T->toks = (char **)malloc(sizeof(char *) * 3);
	if (!T->toks)
	{
		free(T);
		mng_errs(ERROR_MALLOC);
	}
	T->stack = NULL;
	T->line = NULL;
	T->ln = 0;
	return (EXIT_SUCCESS);
}
