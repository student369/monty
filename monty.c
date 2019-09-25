#include "monty.h"

/**
 * main - a program to interpret Monty code
 * @ac: counts args
 * @av: the args
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	size_t n;
	void (*execute)(stack_t **stack, unsigned int line_number);

	T = NULL;
	if (ac != 2)
		mng_errs(ERROR_USAGE_FILE);
	build_things();
	T->fname = av[1];
	T->f = fopen(T->fname, "r");
	if (T->f == NULL)
		mng_errs(ERROR_OPEN_FILE);
	while (getline(&T->line, &n, T->f) > 0)
	{
		T->ln++;
		if (tok_line(T->line) == EXIT_FAILURE)
			continue;
		execute = find_opcode();
		execute(&T->stack, T->ln);
	}
	free_all();
	return (EXIT_SUCCESS);
}
