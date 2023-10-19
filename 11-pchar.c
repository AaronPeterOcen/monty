#include "monty.h"

/**
 * pchar - prints the first character on top of stack
 * @stark: given stack
 * @line_num: line number
 * Return: void
 *
 **/
void pchar(stack_t **stark, unsigned int line_num)
{
	if (stark == NULL || *stark == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (isascii(variables.holder))
		printf("%c\n", variables.holder);
	else
	{
		printf("L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
}
