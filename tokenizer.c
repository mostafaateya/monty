#include "monty.h"

/**
 * tokenizer - breaks the string line into words
 * Return: nothing
 */

void tokenizer(void)
{
	int z = 0;
	char *ss = " \n", *a = NULL, *s = NULL;

	s = malloc(sizeof(char) * (strlen(mos->a) + 1));
	strcpy(s, mos->a);
	mos->n = 0;
	a = strtok(s, ss);
	while (a)
	{
		mos->n += 1;
		a = strtok(NULL, ss);
	}

	mos->s = malloc(sizeof(char *) * (mos->n + 1));
	strcpy(s, mos->a);
	a = strtok(s, ss);
	while (a)
	{
		mos->s[z] = malloc(sizeof(char) * (strlen(a) + 1));
		if (mos->s[z] == NULL)
			monty_error_for_malloc();
		strcpy(mos->s[z], a);
		a = strtok(NULL, ss);
		z++;
	}
	mos->s[z] = NULL;
	free(s);
}
