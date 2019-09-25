#include "monty.h"
/**
 * swap - function to swap two stack elements.
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int t;
	(void)line_number;

	if ((*stack) == NULL || T->len < 2)
	{
		mng_errs(ERROR_SWAP);
	}
	tmp = (*stack);
	while (tmp->prev != NULL)
		tmp = (*stack)->prev;
	t = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = t;
	(*stack) = tmp;
}
