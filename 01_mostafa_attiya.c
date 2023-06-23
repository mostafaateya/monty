#include "monty.h"

/**
 * monty_error_for_usage - prints the msg for usage error
 * Return: exit failure
 */

int monty_error_for_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * monty_error_for_malloc - prints the msg for malloc error
 * Return: exit failure
 */

int monty_error_for_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * monty_error_for_file_opening - prints the msg for file opening error
 * @a: the file name
 * Return: exit failure
 */

int monty_error_for_file_opening(char *a)
{
	fprintf(stderr, "Error: Can't open file %s\n", a);
	return (EXIT_FAILURE);
}

/**
 * monty_error_for_unkown_operation - prints the msg
 * for the invalid instruction error
 * @a: character where the error happened
 * @z: line number where the error happened
 * Return: exit failure
 */

int monty_error_for_unkown_operation(char *a, unsigned int z)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", z, a);
	return (EXIT_FAILURE);
}

/**
 * monty_error_for_invalid_inputs - prints the msg for invalid arguments error
 * @z: line number where the error happened
 * Return: exit failure
 */

int monty_error_for_invalid_inputs(unsigned int z)
{
	fprintf(stderr, "L%u: usage: push integer\n", z);
	return (EXIT_FAILURE);
}
