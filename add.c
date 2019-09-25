#include "monty.h"
/**
 * add - function to add the first two stack elements.
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int t;
	(void)line_number;

	if ((*stack) == NULL || T->len < 2)
	{
		mng_errs(ERROR_ADD);
	}
	tmp = (*stack);
	while (tmp->prev != NULL)
		tmp = (*stack)->prev;
	t = tmp->n + tmp->next->n;
	tmp->next->n = t;
	tmp->next->prev = NULL;
	(*stack) = tmp->next;
	free(tmp);
}
