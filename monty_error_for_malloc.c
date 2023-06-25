#include "monty.h"

/**
 * monty_error_for_malloc - prints a message for malloc error
 * Return: nothing
 */

void monty_error_for_malloc(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_data_stack();
	exit(EXIT_FAILURE);
}
