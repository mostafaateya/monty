#include "monty.h"

/**
 * define_mos - defines a mos
 * Return: nothing
 */

void define_mos(void)
{
	mos  = malloc(sizeof(s_data_s));
	if (mos == NULL)
		monty_error_for_malloc();

	mos->xt = malloc(sizeof(instruction_t));
	if (mos->xt == NULL)
		monty_error_for_malloc();

	mos->ff = NULL;
	mos->top = NULL;
	mos->a = NULL;
	mos->n = 0;
	mos->x = 0;
	mos->nn = 0;
	mos->st = 1;
}
