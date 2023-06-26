#include "monty.h"

/**
 * monty_func_for_pchar - prints the character in
 * the top node of linked list
 * @x: pointer to the top element in a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_pchar(stack_t **x, unsigned int l)
{
	stack_t *top = mos->top;

	(void) x;
	if (top->n >= 0 || top->n <= 127)
		printf("%c\n", top->n);
	else
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", l);
		free_all_memory();
		exit(EXIT_FAILURE);
	}

	if (top == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", l);
		free_all_memory();
		exit(EXIT_FAILURE);
	}

}
