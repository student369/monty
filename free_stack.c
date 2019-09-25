#include "monty.h"
/**
 * free_stack - frees the stack
 *
 * Return: void
 */
void free_stack(void)
{
	stack_t *tmp;
	stack_t *head;

	if (T->stack)
	{
		head = T->stack;
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
}
