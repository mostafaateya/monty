#include "monty.h"

/**
 * monty_func_for_pop - deletes the top element of a stack
 * @x: pointer to the top element of a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_pop(stack_t **x, unsigned int l)
{
	(void) x;

	if (mos->top == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", l);
		free_data_stack();
		exit(EXIT_FAILURE);
	}

	top_element_delete();
	mos->nn -= 1;
}
