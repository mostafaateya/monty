#include "monty.h"

/**
 * monty_func_for_pint - does the pint function
 * @x: pointer to the top element of a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_pint(stack_t **x, unsigned int l)
{
	(void) x;
	if (mos->top == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", l);
		free_data_stack();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", mos->top->n);
}
