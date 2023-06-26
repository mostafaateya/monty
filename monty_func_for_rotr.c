#include "monty.h"

/**
 * monty_func_for_rotr - rotates the bottom value of a stack to top
 * @x: pointer to the top element in a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_rotr(stack_t **x, unsigned int l)
{
	stack_t *top = mos->top;
	stack_t *bottom = mos->top;
	(void)l;

	if (mos->top == NULL || mos->top->next == NULL)
		return;

	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	mos->top = bottom;
	bottom->prev = *x;
	bottom->next = top;
	top->prev = bottom;
}
