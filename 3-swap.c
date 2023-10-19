#include "monty.h"

/**
 * swap - swap first two elements on top of stack
 * @stark: the given stack
 * @line_num: line number
 * Return: void
 *
 **/

void swap(stack_t **stark, unsigned int line_num)
{
	int new;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}
	new = (*stark)->n;
	(*stark)->n = (*stark)->next->n;
	(*stark)->next->n = new;
}
