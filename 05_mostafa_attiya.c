#include "monty.h"

/**
 * monty_func_for_add - adds the top 2 elements of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_add(stack_t **x_top, unsigned int l)
{
	if ((*x_top)->next == NULL || (*x_top)->next->next == NULL)
	{
		monty_error_for_set_op(monty_error_for_small_stack(l, "add"));
		return;
	}
	(*x_top)->next->next->n += (*x_top)->next->n;
	monty_func_for_pop(x_top, l);
}

/**
 * monty_func_for_sub - subtracts the top 2 elements of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_sub(stack_t **x_top, unsigned int l)
{
	if ((*x_top)->next == NULL || (*x_top)->next->next == NULL)
	{
		monty_error_for_set_op(monty_error_for_small_stack(l, "sub"));
		return;
	}
	(*x_top)->next->next->n -= (*x_top)->next->n;
	monty_func_for_pop(x_top, l);
}

/**
 * monty_func_for_div - divides the top 2 elements of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_div(stack_t **x_top, unsigned int l)
{
	if ((*x_top)->next == NULL || (*x_top)->next->next == NULL)
	{
		monty_error_for_set_op(monty_error_for_small_stack(l, "div"));
		return;
	}
	if ((*x_top)->next->n == 0)
	{
		monty_error_for_set_op(monty_error_for_div(l));
		return;
	}
	(*x_top)->next->next->n /= (*x_top)->next->n;
	monty_func_for_pop(x_top, l);
}

/**
 * monty_func_for_mod - computes the modulesof
 * the top 2 elements of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_mod(stack_t **x_top, unsigned int l)
{
	if ((*x_top)->next == NULL || (*x_top)->next->next == NULL)
	{
		monty_error_for_set_op(monty_error_for_small_stack(l, "mod");
		return;
	}
	if ((*x_top)->next->n == 0)
	{
		monty_error_for_set_op(monty_error_for_div(l));
		return;
		}
		(*x_top)->next->next->n %= (*x_top)->next->n;
		monty_func_for_pop(x_top, l);
}

/**
 * monty_func_for_mul - multipliess the top 2 elements of stack linked list
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_mul(stack_t **x_top, unsigned int l)
{
	if ((*x_top)->next == NULL || (*x_top)->next->next == NULL)
	{
		monty_error_for_set_op(monty_error_for_small_stack(l, "mul"));
		return;
	}
	(*x_top)->next->next->n *= (*x_top)->next->n;
	monty_func_for_pop(x_top, l);
}
