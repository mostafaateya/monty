#include "monty.h"

/**
 * top_element_delete - deletes element from top
 * Return: nothing
 */

void top_element_delete(void)
{
	stack_t *x;

	x = mos->top;
	mos->top = x->next;
	free(x);
}
