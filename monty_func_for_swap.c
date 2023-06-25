#include "monty.h"

/**
 * monty_func_for_swap - does the swap function
 * @x: pointer to the top element of a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_swap(stack_t **x, unsigned int l)
{
	stack_t *top1, *top2;

	(void) x;
	if (mos->nn < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", l);
		free_all_memory();
		exit(EXIT_FAILURE);
	}

	top1 = mos->top;
	top2 = top1->next;
	top1->next = top2->next;
	if (top1->next)
	{
		top1->next->prev = top1;
	}
	top2->next = top1;
	top1->prev = top2;
	top2->prev = NULL;
	mos->top = top2;
}
