#include "monty.h"
/**
 * _div - function to divide the first two stack elements.
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int t;
	(void)line_number;

	if ((*stack) == NULL || T->len < 2)
	{
		mng_errs(ERROR_DIV);
	}
	tmp = (*stack);
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	if (tmp->n == 0)
		mng_errs(ERROR_ZERO);
	t = tmp->next->n / tmp->n;
	tmp->next->n = t;
	tmp->next->prev = NULL;
	(*stack) = tmp->next;
	free(tmp);
}