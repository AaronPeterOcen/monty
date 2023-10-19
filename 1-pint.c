#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stark: the given stack
 * @line_num: line number
 * Return: void
 *
 **/

void pint(stack_t **stark, unsigned int line_num)
{
	if (stark == NULL || *stark == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stark)->n);
}
