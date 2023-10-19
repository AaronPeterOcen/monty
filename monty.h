#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

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

/* PRIMARY INTERPRETER FUNCTIONS */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

/* OPCODE FUNCTIONS */
void mpush(stack_t **stk, unsigned int ln);
void mpall(stack_t **stk, unsigned int ln);
void mpint(stack_t **stk, unsigned int ln);
void mpop(stack_t **stk, unsigned int ln);
void mswap(stack_t **stk, unsigned int ln);

void madd(stack_t **stk, unsigned int ln);
void msub(stack_t **stk, unsigned int ln);
void mdiv(stack_t **stk, unsigned int ln);
void mmul(stack_t **stk, unsigned int ln);
void mmod(stack_t **stk, unsigned int ln);

void mnop(stack_t **stk, unsigned int ln);
void mpchar(stack_t **stk, unsigned int ln);
void mpstr(stack_t **stk, unsigned int ln);

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);


/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int usage_error(void);
int malloc_error(void);
int f_open_error(char *fn);
int unknown_op_error(char *opcode, unsigned int ln);
int no_int_error(unsigned int ln);

int pop_error(unsigned int ln);
int pint_error(unsigned int ln);
int short_stack_error(unsigned int ln, char *op);
int div_error(unsigned int ln);
int pchar_error(unsigned int ln, char *msg);

#endif /* __MONTY_H__ */
