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
		{"swap", swap}, {NULL, NULL}
	};
	i = ins;
	opcode = T->toks[0];
	while (i->opcode && strncmp(i->opcode, opcode, strlen(opcode)))
		i++;
	if (!i->f)
		mng_errs(ERROR_UNKNOWN);
	return (i->f);
}
