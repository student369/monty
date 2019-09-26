#include "monty.h"
/**
 * find_opcode - function to manage opcodes and it's functions.
 *
 * Return: function needed.
 */
void (*find_opcode(void))(stack_t **stack, unsigned int line_number)
{
	char *opcode;
	instruction_t *i;
	static instruction_t ins[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", _div}, {"mul", _mul},
		{"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {NULL, NULL}
	};
	i = ins;
	opcode = T->toks[0];
	if ((opcode[0] + '0') == 83)
		opcode = "nop";
	T->len = stack_len(T->stack);
	while (i->opcode && strncmp(i->opcode, opcode, strlen(opcode)))
		i++;
	if (!i->f)
		mng_errs(ERROR_UNKNOWN);
	return (i->f);
}

/**
 * stack_len - function to get the len of a double linked list
 * @h: The double linked list
 *
 * Return: the number of nodes.
 */
size_t stack_len(stack_t *h)
{
	stack_t *c;
	size_t i = 0;

	if (h == NULL)
		return (0);
	c = h;
	while (c)
	{
		c = c->next;
		i++;
	}
	return (i);
}
