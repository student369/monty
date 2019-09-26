#include "monty.h"
/**
 * _pchar - prints the character of the number
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if ((*stack) == NULL)
		mng_errs(ERROR_PCHAR);
	if (!((*stack)->n > -1 && (*stack)->n <= 127))
		mng_errs(ERROR_PCHAR_OUT);
	printf("%c\n", (*stack)->n);
}
