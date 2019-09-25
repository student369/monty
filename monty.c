#include "monty.h"
void (*opcode_fnc[])(stack_t **stack,
		     unsigned int line_number) = {&push, &pall};
/**
  * num_opcodes - get the count of the opcodes.
  *
  * Return: the count of opcodes
  */
int num_opcodes(char **ops)
{
	return (sizeof(ops) / sizeof(char *));
}
/**
 * execute - funtion to execute he opcode
 * @ins: The instruction
 * @ln: The line
 * @v: The value
 *
 * Return: 1 or error
 */
void execute(char **opcodes, instruction_t *ins, unsigned int ln, int v)
{
	stack_t *st;
	int i;

	for (i = 0; i < num_opcodes(opcodes); i++)
	{
		st->n = v;
		st->next = NULL;
		st->prev = NULL;
		if (strcmp(ins->opcode, opcodes[i]) == 0)
			(*opcode_fnc[i])(&st, ln);
	}
}

/**
 * interp_l - funtion to interpret the line an take the tokens.
 * @l: The line to interpret
 *
 * Return: The tokenized version of the line
 */

char **interp_l(char *l)
{
	int buffs = L_LINE, pos = 0;
	char *tok, **toks_bk;
	char **toks = (char **)malloc(buffs * sizeof(char *));

	if (!toks)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tok = strtok(l, TOK_DELIM);
	while (tok != NULL)
	{
		toks[pos] = tok;
		pos++;
		if (pos >= buffs)
		{
			buffs += TOK_BUFF;
			toks_bk = toks;
			toks = realloc(toks, buffs * sizeof(char *));
			if (!toks)
			{
				free(toks_bk);
				printf("Error: reallocing\n");
				exit(EXIT_FAILURE);
			}
		}
		tok = strtok(NULL, TOK_DELIM);
	}
	toks[pos] = NULL;
	return (toks);
}

/**
 * isValidOpcode - verify if the opcode it's correct
 * @op: The opcode to validate
 *
 * Return: 1 or 0
 */
int isValidOpcode(char **ops, char *op)
{
	int i;
	int len = num_opcodes(ops);

	for (i = 0; i < len; i++)
	{
		if (strcmp(op, ops[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * main - Monty a simple interpreter of Monty language
 *
 * @ac: count of arguments
 * @av: The arguments passed
 *
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int ac, char *av[])
{
	FILE *f;
	int nl = 1, v;
	char *ln;
	char **toks;
	char bff[L_LINE];
	instruction_t *ins;
	char *opcodes[] = {"push", "pall"};

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(av[1], "r");
	if (!f)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((ln = fgets(bff, L_LINE, f)))
	{
		toks = interp_l(ln);
		if (isValidOpcode(opcodes, toks[0]))
		{
			v = atoi(toks[1]);
			printf("L%i: opcode: %s param: %i\n", nl, toks[0], v);
			ins->opcode = toks[0];
			execute(opcodes, ins, nl, v);
		}
		else
		{
			printf("L%i: unknown instruction %s\n", nl, toks[0]);
			exit(EXIT_FAILURE);
		}
		free(toks);
		nl++;
	}
	fclose(f);
	exit(EXIT_SUCCESS);
}
