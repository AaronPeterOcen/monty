#include "monty.h"

/**
 * free_stark - function to free stack
 * @stark: the stack
 * @line_num: line number
 * Return: void
 *
 **/

void free_stark(stack_t **stark, unsigned int line_num)
{
	if (stark == NULL)
		return;
	while (*stark != NULL)
		pop(stark, line_num);
}
