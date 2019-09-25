#include "monty.h"
/**
 * pall - prints the stack
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	for (tmp = *stack; tmp; tmp = tmp->next)
		printf("%i\n", tmp->n);
}
