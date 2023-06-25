#include "monty.h"

/**
 * free_stack - frees a stack
 * @x: pointer to the top element of a stack
 * Return: nothing
 */

void free_stack(stack_t **x)
{
	stack_t *top = *x;

	while (*x)
	{
		top = (*x)->next;
		free(*x);
		*x = top;
	}
}

/**
 * initiation_stack - initializes a stack
 * @x: pointer to the top element of a stack
 * Return: exit success or exit failure
 */

int initiation_stack(stack_t **x)
{
	stack_t *top;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
		return (monty_error_for_malloc());
	top->n = MOS_STACK;
	top->prev = NULL;
	top->next = NULL;
	*x = top;
	return (EXIT_SUCCESS);
}

/**
 * monty_func_for_check - checks if a linked list is in a stack or queue
 * @x: pointer to the top element of a stack or queue
 * Return: 0 if stack, 1 if queue or 2 otherwise
 */

int monty_func_for_check(stack_t *x)
{
	if (x->n == MOS_STACK)
		return (MOS_STACK);
	else if (x->n == MOS_QUEUE)
		return (MOS_QUEUE);
	return (2);
}
