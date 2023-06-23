#include "monty.h"

/**
 * monty_func_for_nop - Does nothing
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_nop(stack_t **x_top, unsigned int l)
{
	(void)x_top;
	(void)l;
}

/**
 * monty_func_for_pchar - prints the character
 * in the top value of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_pchar(stack_t **x_top, unsigned int l)
{
	if ((*x_top)->next == NULL)
	{
		monty_error_for_set_op(monty_error_for_pchar(l, "stack empty"));
		return;
	}
	if ((*x_top)->next->n == 0 || (*x_top)->next->n > 127)
	{
		monty_error_for_set_op(monty_error_for_pchar(l, "value out of range"));
		return;
	}
	printf("%c\n", (*x_top)->next->n);
}

/**
 * monty_func_for_pstr - prints the string contained in stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_pstr(stack_t **x_top, unsigned int l)
{
	stack_t *top = (*x_top)->next;

	while (top && top->n != 0 && (top->n > 0 && top->n <= 127))
	{
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
	(void)l;
}
