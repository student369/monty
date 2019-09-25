#include "monty.h"
/**
 * sub - function to substract the two first stack elements.
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int t;
	(void)line_number;

	if ((*stack) == NULL || T->len < 2)
	{
		mng_errs(ERROR_SUB);
	}
	tmp = (*stack);
	while (tmp->prev != NULL)
		tmp = (*stack)->prev;
	t = tmp->next->n - tmp->n;
	tmp->next->n = t;
	tmp->next->prev = NULL;
	(*stack) = tmp->next;
	free(tmp);
}
