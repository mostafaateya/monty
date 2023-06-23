#include "mont.h"

/**
 * monty_func_for_rotl - rotates the top value
 * of a stack linked list to the bottom
 * in the top value of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_rotl(stack_t **x_top, unsigned int l)
{
	stack_t *x, *y;

	if ((*x_top)->next == NULL || (*x_top)->next->next == NULL)
		return;
	x = (*x_top)->next;
	y = (*x_top)->next;
	while (y->next != NULL)
		y = y->next;
	x->next->prev = *x_top;
	(*x_top)->next = x->next;
	y->next = x;
	x->next = NULL;
	x->prev = y;
	(void)l;
}

/**
 * monty_func_for_rotr - rotates the bottom
 * value of a stack linked list to the top
 * in the top value of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_rotr(stack_t **x_top, unsigned int l)
{
	stack_t *x, *y;

	if ((*x_top)->next == NULL || (*x_top)->next->next == NULL)
		return;
	x = (*x_top)->next;
	y = (*x_top)->next;
	while (y->next != NULL)
		y = y->next;
	y->prev->next = NULL;
	(*x_top)->next = y;
	y->prev = *x_top;
	y->next = x;
	x->prev = y;
	(void)l;
}

/**
 * monty_func_for_stack - convertes a queue to a stack
 * in the top value of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_stack(stack_t **x_top, unsigned int l)
{
	(*x_top)->n = MOS_STACK;
	(void)l;
}

/**
 * monty_func_for_queue - convertes a stack to a queue
 * in the top value of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_queue(stack_t **x_top, unsigned int l)
{
	(*x_top)->n = MOS_QUEUE;
	(void)l;
}
