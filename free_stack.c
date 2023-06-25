#include "monty.h"

/**
 * free_stack - frees all element in a stack
 * @x: pointer to the first element in a stack
 * Return: nothing
 */

void free_stack(stack_t *x)
{
	if (x == NULL)
		return;

	if (x->next != NULL)
	{
		free_stack(x->next);
	}
	free(x);
}
