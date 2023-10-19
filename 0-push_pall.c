#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stark: top of stack
 * @line_num: line number for the passed token
 * Return: void
 *
 **/
void push(stack_t **stark, unsigned int line_num)
{
	stack_t *new;

	if (stark == NULL)
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}
	new->n = variables.holder;
	new->prev = NULL;
	new->next = *stark;

	if (*stark != NULL)
		(*stark)->prev = new;
	*stark = new;
}

/**
 * pall - function to print all members of the stack
 * @stark: top of stack
 * @line_num: line number
 * Return: void
 *
 **/
void pall(stack_t **stark, unsigned int line_num)
{
	stack_t *print;

	if (stark == NULL)
	{
		printf("L%d: usage: stack invalid\n", line_num);
		exit(EXIT_FAILURE);
	}

	print = *stark;

	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}
