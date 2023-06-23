#include "monty.h"

/**
 * monty_func_for_push - pushes element to stack
 * @x_top: pointer to the top element
 * @l: line number
 * Return: nothing
 */

void monty_func_for_push(stack_t **x_top, unsigned int l)
{
	stack_t *n, *top = *x_top;

	if (!ex.data.value)
	{
		fprintf(stderr, "L%u: usage: push integer\n", l);
		free(mos.line);
		fclose(mos.fp);
		free_stack(*x_top);
		exit(EXIT_FAILURE);
	}

	n = malloc(sizeof(stack_t));
	if (!n)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(mos.line);
		fclose(mos.fp);
		free_stack(*x_top);
		exit(EXIT_FAILURE);
	}
	n->n = mos.int_value;

	if (!top)
	{
		n->next = NULL;
		n->prev = NULL;
		*x_top = n;
	}
	else
	{
		n->next = NULL;
		n->prev = top;
		top->next = n;
		*x_top = n;
	}
}

/**
 * monty_func_for_pall - prints all elements on stack
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_pall(stack_t **x_top, unsigned int l)
{
	stack_t *top = *x_top;

	(void)l;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->prev;
	}
}

/**
 * monty_func_for_pint - prints the value at the top of the stack
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_pint(stack_t **x_top, unsigned int l)
{
	if (!(*x_top))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", l);
		free(mos.line);
		fclose(mos.fp);
		free_stack(*x_top);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*x_top)->n);
}

/**
 * monty_func_for_pop - removes the top element of the stack
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_pop(stack_t **x_top, unsigned int l)
{
	stack_t *top = *x_top;

	if (!top)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l);
		free(mos.line);
		fclose(mos.fp);
		free_stack(*x_top);
		exit(EXIT_FAILURE);
	}
	top = *x_top;
	if (top->prev != NULL)
	{
		top->prev->next = NULL;
		*x_top = top->prev;
	}
	else
		*x_top = NULL;

	free(top);
}

/**
 * monty_func_for_swap -swaps the top 2 elements of the stack
 * @x_top: pointer to the top element
 * @l: needed input
 * Return: nothing
 */

void monty_func_for_swap(stack_t **x_top, unsigned int l)
{
	stack_t *top = *x_top;
	int i = 0;

	if (!top || !top->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", l);
		free(mos.line);
		fclose(mos.fp);
		free_stack(*x_top);
		exit(EXIT_FAILURE);
	}

	i = top->prev->n;
	top->prev->n = top->n;
	top->n = i;
}
