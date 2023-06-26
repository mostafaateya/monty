#include "monty.h"

/**
 * monty_func_for_rotl - rotates the top value of a stack to bottom
 * @x: pointer to the top element in a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_rotl(stack_t **x, unsigned int l)
{
	stack_t *top = mos->top;
	stack_t *bottom = mos->top;
	(void)l;

	if (mos->top == NULL || mos->top->next == NULL)
		return;

	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *x;
	mos->top = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
}
