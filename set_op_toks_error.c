#include "monty.h"

/**
 * set_op_error - Sets last element of op_toks to be an error code.
 * @err_code: Integer to store as a string in op_toks.
 */

void set_op_error(int err_code)
{
	int toklen = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toklen = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toklen + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	
	for (; i < toklen; i++)
	{
		new_toks[i] = op_toks[i];
	}
	
	exit_str = get_int(err_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
