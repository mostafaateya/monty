#include "monty.h"

/**
 * validate_num - checks the validation of a number
 * @a: string input
 * Return: 1 on Success of 0 on Failure
 */

int validate_num(char *a)
{
	int z = 0;

	while (a[z])
	{
		if (z == 0 && a[z] == '-' && a[z + 1])
		{
			z++;
			continue;
		}
		if (a[z] < '0' || a[z] > '9')
			return (0);
		z++;
	}
	return (1);
}
