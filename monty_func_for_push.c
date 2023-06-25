#include "monty.h"

/**
 * monty_func_for_push - does the push function
 * @x: pointer to the top element of a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_push(stack_t **x, unsigned int l)
{
	if (mos->n <= 1 || !(validate_num(mos->s[1])))
	{
		free_data_stack();
		dprintf(2, "L%d: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	*x = malloc(sizeof(stack_t));
	if (*x == NULL)
		monty_error_for_malloc();
	(*x)->next = (*x)->prev = NULL;
	(*x)->n = (int) atoi(mos->s[1]);
	if (mos->top == NULL)
		mos->top = *x;
	else
	{
		if (mos->st)
		{
			(*x)->next = mos->top;
			mos->top->prev = *x;
			mos->top = *x;
		}
		else
		{
			stack_t *n = mos->top;

			while (n->next)
				n = n->next;
			n->next = *x;
			(*x)->prev = n;
		}
	}
	mos->nn += 1;
}
