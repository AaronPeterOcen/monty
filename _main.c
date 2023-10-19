#include "monty.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: arguments passed
 *
 * Return: EXIT_SUCCESS (0), or EXIT_FAILURE (1)
 *
 **/

int main(int argc, char **argv)
{
	FILE *file;
	char *buff = NULL, *string;
	size_t s = 0;
	unsigned int line_num = 1;
	stack_t *stark = NULL;

	variables.check = 0;

	if (argc != 2)
	{
		printf("usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &s, file) != -1)
	{
		if (*buff != '\n')
		{
			string = strtok(buff, "\n");
			_tokenize(string, &stark, line_num);
		}
		line_num++;
	}
	fclose(file);
	free(buff);
	if (stark != NULL)
		free_stark(&stark, line_num);
	return (EXIT_SUCCESS);
}

/**
 * _tokenize - function to tokenize strings and commands
 * @string: string to be tokenized
 * @stark: pointer to the stack
 * @line_num: line number
 * Return: void
 *
 **/
void _tokenize(char *string, stack_t **stark, unsigned int line_num)
{
	char *token;
	char *tokens;

	token = strtok(string, " ");
	if (token == NULL || *token == ' ' || *token == '\n' || *token == '#')
		return;
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (!check_digit(token))
		{
			printf("L%d: push integer\n", line_num);
			free_stark(stark, line_num);
			exit(EXIT_FAILURE);
		}
		variables.holder = atoi(token);
		_opcode(tokens, stark, line_num);
	}
	else
		_opcode(token, stark, line_num);
}

/**
 * check_digit - checks if string is a number
 * @token: string to check
 * Return:  on success, 1 on failure
 *
 **/
int check_digit(char *token)
{
	if (token == NULL)
		return (0);
	if (*token == '-')
		token++;
	while (*token != '\0')
	{
		if (!isdigit(*token))
			return (0);
		token++;
	}
	token++;
	return (1);
}
