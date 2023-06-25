#include "monty.h"

/**
 * check_argv - checks the mos validity
 * @z: number of mos
 * Return: nothing
 */

void check_argv(int z)
{
	if (z == 2)
		return;

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
