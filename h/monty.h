#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*INT FUNCS*/
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

/*FUNCS*/
void montypush(stack_t **stack, unsigned int ln);
void montypall(stack_t **stack, unsigned int ln);
void montypint(stack_t **stack, unsigned int ln);
void montypop(stack_t **stack, unsigned int ln);
void montyswap(stack_t **stack, unsigned int ln);
void montyadd(stack_t **stack, unsigned int ln);
void montynop(stack_t **stack, unsigned int ln);
void montysub(stack_t **stack, unsigned int ln);
void montydiv(stack_t **stack, unsigned int ln);
void montymul(stack_t **stack, unsigned int ln);
void montymod(stack_t **stack, unsigned int ln);
void montypchar(stack_t **stack, unsigned int ln);
void montypstr(stack_t **stack, unsigned int ln);
void montyrotl(stack_t **stack, unsigned int ln);
void montyrotr(stack_t **stack, unsigned int ln);
void montystack(stack_t **stack, unsigned int ln);
void montyqueue(stack_t **stack, unsigned int ln);

/*STD LIB FUNCS*/
char **strtow(char *str, char *delims);
char *get_int(int n)

/*ERRORS 1*/
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int ln);
int no_int_error(unsigned int ln);
/**/
int pop_error(unsigned int ln);
int pint_error(unsigned int ln);
int short_stack_error(unsigned int ln, char *op);
int div_error(unsigned int ln);
int pchar_error(unsigned int ln, char *message);

#endif
