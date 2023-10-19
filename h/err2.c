#include "monty.h"

int short_stack_error(unsigned int ln, char *op);
int div_error(unsigned int ln);
int pop_error(unsigned int ln);
int div_error(unsigned int ln);
int pchar_error(unsigned int ln, char *msg);

/**
 * pop_error - Prints pop error messages for empty stacks.
 * @ln: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int ln)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", ln);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 * @ln: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int ln)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @ln: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int ln, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", ln, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division error messages for division by 0.
 * @ln: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int ln)
{
	fprintf(stderr, "L%u: division by zero\n", ln);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @ln: Line number in Monty bytecodes file where error occurred.
 * @msg: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int ln, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", ln, msg);
	return (EXIT_FAILURE);
}
