#include "monty.h"
/**
 * _rotr - function to reverse the stack to bottom.
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	int f = 0, l = 0;
	stack_t *tmp;
	(void)line_number;

	if (stack && (*stack))
	{
		tmp = (*stack);
		l = tmp->n;
		for (; tmp->next; tmp = tmp->next)
		{
			f = l;
			l = tmp->next->n;
			tmp->next->n = f;
		}
		(*stack)->n = l;
	}
}
