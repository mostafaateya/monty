#include "monty.h"

/**
 * monty_func_for_queue - convertes a stack to a queue
 * @x: pointer to the top element of a stack
 * @l: line number
 * Return: nothing
 */

void monty_func_for_queue(stack_t **x, unsigned int l)
{
	(*x)->n = 1;
	(void) l;
}
