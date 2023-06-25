#include "monty.h"

/**
 * monty_func_for_run - executes the xt instruction
 * Return: nothing
 */

void monty_func_for_run(void)
{
	stack_t *x = NULL;

	if (mos->n == 0)
		return;

	mos->xt->f(&x, mos->x);
}
