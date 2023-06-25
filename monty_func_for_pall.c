#include "monty.h"

/**
 * monty_func_for_pall - does the pall function
 * @x: pointer to the top element of a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_pall(stack_t **x, unsigned int l)
{
	stack_t *n;

	if (mos->top == NULL)
		return;
	(void) l;
	(void) x;

	n = mos->top;
	while (n != NULL)
	{
		printf("%d\n", n->n);
		n = n->next;
	}
}
