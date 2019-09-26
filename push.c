#include "monty.h"
/**
 * push - add a value to the stack
 * @stack: the stack
 * @line_number: The line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *nw = NULL;
	char *n;
	(void)line_number;

	if (T->toks[1] == NULL)
		mng_errs(ERROR_PUSH);
	else
		n = T->toks[1];
	if (are_digits(n) == 1)
	{
		nw = (stack_t *)malloc(sizeof(stack_t));
		if (nw == NULL)
			mng_errs(ERROR_MALLOC);
	}
	else
		mng_errs(ERROR_PUSH);
	nw->n = atoi(n);
	if (T->format == STACK)
		add_stack(stack, nw);
	else if (T->format == QUEUE)
		add_queue(stack, nw);

}

/**
 * add_stack - add a new value to the stack
 * @stack: the stack
 * @nw: The new element
 *
 * Return: void
 */
void add_stack(stack_t **stack, stack_t *nw)
{
	nw->prev = NULL;
	nw->next = (*stack);
	if ((*stack))
		(*stack)->prev = nw;
	(*stack) = nw;
}

/**
 * add_queue - add a new value to the queue
 * @queue: the queue
 * @nw: The new element
 *
 * Return: void
 */
void add_queue(stack_t **queue, stack_t *nw)
{
	nw->prev = NULL;
	nw->next = (*queue);
	if ((*queue))
		(*queue)->prev = nw;
	(*queue) = nw;
}
