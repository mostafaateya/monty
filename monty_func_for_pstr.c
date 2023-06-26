#include "monty.h"

/**
 * monty_func_for_pstr - prints the string contained in a linked list
 * @x: pointer to the top element in a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_pstr(stack_t **x, unsigned int l)
{
	stack_t *top = mos->top;
	(void)x;
	(void)l;

	while (top && top->n != 0 && (top->n > 0 && top->n <= 127))
	{
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}
