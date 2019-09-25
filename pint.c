#include "monty.h"
/**
 * pint - prints the top value of the stack
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if ((*stack) != NULL)
		printf("%i\n", (*stack)->n);
}
