#include "monty.h"

/**
 * free_operational_str - frees the global operasional_str of strings
 * Return: nothing
 */

void free_operational_str(void)
{
	size_t x = 0;

	if (operational_str == NULL)
		return;
	for (x = 0; operational_str[x]; x++)
		free(operational_str[x]);
	free(operational_str);
}

/**
 * length_operational_str - gets the length of operational_str
 * Return: length of operational_str
 */

unsigned int length_operational_str(void)
{
	unsigned int x = 0;

	while (operational_str[x])
		x++;
	return (x);
}

/**
 * empty_or_not - checks if a line contains delimiters
 * @a: pointer to the line
 * @s: string of delimiter characters
 * Return: 1 if contains delimiter or 0
 */

int empty_or_not(char *a, char *s)
{
	int x, y;

	for (x = 0; a[x]; x++)
	{
		for (y = 0; s[y]; y++)
		{
			if (a[x] == s[y])
				break;
		}
		if (s[y] == '\0')
			return (0);
	}
	return (1);
}

/**
 * monty_func_for_match - matches the operation with its function
 * @opcode: input operation
 * Return: pointer to operations function
 */

void (*monty_func_for_match(char *opcode))(stack_t **, unsigned int)
{
	instruction_t func_for_op[] = {
		{"push", monty_func_for_push},
		{"pall", monty_func_for_pall},
		{"pint", monty_func_for_pint},
		{"pop", monty_func_for_pop},
		{"swap", monty_func_for_swap},
		{"add", monty_func_for_add},
		{"sub", monty_func_for_sub},
		{"div", monty_func_for_div},
		{"mul", monty_func_for_mul},
		{"mod", monty_func_for_mod},
		{"nop", monty_func_for_nop},
		{"pchar", monty_func_for_pchar},
		{"pstr", monty_func_for_pstr},
		{"rotl", monty_func_for_rotl},
		{"rotr", monty_func_for_rotr},
		{"stack", monty_func_for_stack},
		{"queue", monty_func_for_queue},
		{NULL, NULL}
	};
	int x;

	for (x = 0; func_for_op[x].opcode; x++)
	{
		if (strcmp(opcode, func_for_op[x].opcode) == 0)
			return (func_for_op[x].f);
	}
	return (NULL);
}

/**
 * monty_func_for_run - executes the monty script files
 * @ff: monty script file
 * Return: exit success or exit failure
 */

int monty_func_for_run(FILE *ff)
{
	stack_t *s = NULL;
	char *a = NULL;
	size_t len = 0;
	size_t _exit = EXIT_SUCCESS;
	unsigned int l = 0, ll = 0;
	void (*func_op)(stack_t **, unsigned int);

	if (initiation_stack(&s) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&a, &len, ff) != -1)
	{
		l++;
		operational_str = seperate_str(a, MOS_DELIMS);
		if (operational_str == NULL)
		{
			if (empty_or_not(a, MOS_DELIMS))
				continue;
			free_stack(&s);
			return (monty_error_for_malloc()); }
		else if (operational_str[0][0] == '#')
		{
			free_operational_str();
			continue; }
		func_op = monty_func_for_match(operational_str[0]);
		if (func_op == NULL)
		{
			free_stack(&s);
			_exit = monty_error_for_unkown_operation(operational_str[0], l);
			free_operational_str();
			break; }
		ll = length_operational_str();
		func_op(&s, l);
		if (length_operational_str() != ll)
		{
			if (operational_str && operational_str[ll])
				_exit = atoi(operational_str[ll]);
			else
				_exit = EXIT_FAILURE;
			free_operational_str();
			break; }
		free_operational_str(); }
	free_stack(&s);
	if (a && *a == 0)
	{
		free(a);
		return (monty_error_for_malloc()); }
	free(a);
	return (_exit);
}

