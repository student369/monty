#ifndef MONTY_H
#define MONTY_H
#define L_LINE 255
#define TOK_DELIM " \n"
#define TOK_BUFF 64
#define ERROR_MALLOC 0
#define ERROR_USAGE_FILE 1
#define ERROR_OPEN_FILE 2
#define ERROR_UNKNOWN 3
#define ERROR_PUSH 4
#define ERROR_PINT 5
#define ERROR_POP 6
#define ERROR_SWAP 7
#define ERROR_ADD 8
#define ERROR_SUB 9
#define ERROR_DIV 10
#define ERROR_ZERO 11
#define ERROR_MUL 12
#define ERROR_MOD 13
#define ERROR_PCHAR 14
#define ERROR_PCHAR_OUT 15
#define STACK 0
#define QUEUE 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct things_s -a truct to point others structs
 * @fname: The filename
 * @stack: The stack
 * @ln: The line
 * @toks: The tokens
 * @ln: The line number
 * @f: The file
 */
typedef struct things_s
{
	char *fname;
	stack_t *stack;
	char *line;
	char **toks;	
        unsigned int ln;
	FILE *f;
	size_t len;
	int format;
} things_t;
extern things_t *T;
things_t *T;
char **interp_l(char *l);
void (*find_opcode(void))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void add_stack(stack_t **stack, stack_t *nw);
void add_queue(stack_t **queue, stack_t *nw);
int num_opcodes(char **ops);
int tok_line(char *line);
void mng_errs(int e);
void free_all(void);
void free_stack(void);
void add_stack(stack_t **stack, stack_t *nw);
int build_things(void);
int are_digits(char *s);
size_t stack_len(stack_t *h);
#endif /* MONTY_H */
