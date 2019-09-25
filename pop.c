#include "monty.h"
/**
 * pop - remove the top element of the stack
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL)
	{
		mng_errs(ERROR_POP);
	}
	else if ((*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		tmp->prev = NULL;
		free((*stack));
		(*stack) = tmp;
	}
	else
	{
		free((*stack));
		(*stack) = NULL;
	}
}
