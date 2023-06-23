#include "monty.h"

/**
 * monty_error_for_pop - prints the msg for pop error
 * @z: line number where the error happened
 * Return: exit failure
 */

int monty_error_for_pop(unsigned int z)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", z);
	return (EXIT_FAILURE);
}

/**
 * monty_error_for_pint - prints the msg for pint error
 * @z: line number where the error happened
 * Return: exit failure
 */

int monty_error_for_pint(unsigned int z)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", z);
	return (EXIT_FAILURE);
}

/**
 * monty_error_for_small_stack - prints the msg for error
 * when stack nodes are smaller than 2 nodes
 * @z: line number where the error happened
 * @a: operation where the error happened
 * Return: exit failure
 */

int monty_error_for_small_stack(unsigned int z, char *a)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", z, a);
	return (EXIT_FAILURE);
}

/**
 * monty_error_for_div - prints the msg for the division error
 * @z: line number where the error happened
 * Return: exit failure
 */

int monty_error_for_div(unsigned int z)
{
	fprintf(stderr, "L%u: division by zero\n", z);
	return (EXIT_FAILURE);
}

/**
 * monty_error_for_pchar - prints the msg for pchar error
 * @z: line number where the error happened
 * @a: the printed error message
 * Return: exit failure
 */

int monty_error_for_pchar(unsigned int z, char *a)
{
	fprintf(stderr, "L%u: can't pchar, %S\n", z, a);
	return (EXIT_FAILURE);
}
