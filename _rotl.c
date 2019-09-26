#include "monty.h"
/**
 * _rotl - function to reverse the stack.
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *tmp;
	(void)line_number;

	if (stack && (*stack))
	{
		i = (*stack)->n;
		for (tmp = (*stack); tmp->next; tmp = tmp->next)
			tmp->n = tmp->next->n;
		tmp->n = i;
	}
}
