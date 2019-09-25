#include "monty.h"
/**
 * free_all - frees all the allocs.
 *
 * Return: void
 */
void free_all(void)
{
	if (T != NULL)
		fclose(T->f);
	if (T->line != NULL)
		free(T->line);
	if (T->toks != NULL)
		free(T->toks);
	free_stack();
	free(T);
}
