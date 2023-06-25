#include "monty.h"

/**
 * free_mos - frees all data in mos
 * Return: nothing
 */

void free_mos(void)
{
	if (mos->top)
		free_stack(mos->top);

	mos->top = NULL;
}

/**
 * free_data_stack - frees all mos
 * Return: nothing
 */

void free_data_stack(void)
{
	if (mos == NULL)
		return;

	if (mos->xt)
	{
		free(mos->xt);
		mos->xt = NULL;
	}
	free_mos();
	if (mos->a)
	{
		free(mos->a);
		mos->a = NULL;
	}
	free(mos);
}
