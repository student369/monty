#include "monty.h"
/**
 * _pstr - prints the string begining to the top stack
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int av;
	(void)line_number;

	if ((*stack) == NULL)
		printf("\n");
	else
	{
		for (tmp = (*stack); tmp; tmp = tmp->next)
		{
			av = tmp->n;
			if (!(av > -1 && av <= 127) || av == 0)
				break;
			printf("%c", av);
		}
		printf("\n");
	}
}
