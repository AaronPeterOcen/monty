#include "monty.h"

/**
 * pop -function to pop the top of stack
 * @stark: top of stack
 * @line_num: line number
 * Return: void
 *
 **/

void pop(stack_t **stark, unsigned int line_num)
{
	if (stark == NULL || *stark == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stark)->next != NULL)
	{
		*stark = (*stark)->next;
		variables.holder = (*stark)->n;
		free((*stark)->prev);
		(*stark)->prev = NULL;
	}
	else
	{
		free(*stark);
		*stark = NULL;
	}
}
