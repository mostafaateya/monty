#include "monty.h"

/**
 * monty_func_for_mul - multiblies the top 2 elements in a stack
 * @x: pointer to the top element in a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_mul(stack_t **x, unsigned int l)
{
	stack_t *top1, *top2;

	(void) x;
	if (mos->nn < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", l);
		free_all_memory();
		exit(EXIT_FAILURE);
	}
	top1 = mos->top;
	top2 = top1->next;

	top2->n = top2->n * top1->n;
	top_element_delete();
	mos->nn -= 1;
}
