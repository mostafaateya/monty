#include "monty.h"

/**
 * monty_error_for_message - prints error message for invalid instructions
 * Return: nothing
 */

void monty_error_for_message(void)
{
	dprintf(2, "L%d: unknown instruction %s\n", mos->x, mos->s[0]);
	free_all_memory();
	exit(EXIT_FAILURE);
}

/**
 * setting_for_instruction - sets the settings for instruction
 * Return: nothing
 */

void setting_for_instruction(void)
{
	int z = 0;
	instruction_t a[] = {
		{"push", &monty_func_for_push},
		{"pop", &monty_func_for_pop},
		{"pint", &monty_func_for_pint},
		{"swap", &monty_func_for_swap},
		{"nop", &monty_func_for_nop},
		{"add", &monty_func_for_add},
		{"sub", &monty_func_for_sub},
		{"mul", &monty_func_for_mul},
		{"div", &monty_func_for_div},
		{"mod", &monty_func_for_mod},
		{"pall", &monty_func_for_pall},
		{NULL, NULL}
	};
	if (mos->n == 0)
		return;
	if (mos->s[0][0] == '#')
	{
		mos->xt->opcode = "nop";
		mos->xt->f = monty_func_for_nop;
		return;
	}
	for (; a[z].opcode != NULL; z++)
	{
		if (strcmp(a[z].opcode, mos->s[0]) == 0)
		{
			mos->xt->opcode = a[z].opcode;
			mos->xt->f = a[z].f;
			return;
		}
	}
	monty_error_for_message();
}
