#include "monty.h"

/**
 * monty_error_for_set_op - sets last element of operational_str to be x
 * @x: integer input to store
 * Return: nothing
 */

void monty_error_for_set_op(int x)
{
	int l = 0, z = 0;
	char *s = NULL;
	char **a = NULL;

	l = length_operational_str();
	a = malloc(sizeof(char *) * (l + 2));
	if (!operational_str)
	{
		monty_error_for_malloc();
		return;
	}
	while (z < l)
	{
		a[z] = operational_str[z];
		z++;
	}
	s = pointer_to_int(x);
	if (!s)
	{
		free(a);
		monty_error_for_malloc();
		return;
	}
	a[z++] = s;
	a[z] = NULL;
	free(operational_str);
	operational_str = a;
}
