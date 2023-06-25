#include "monty.h"

/**
 * free_tokenizer - frees all token reserved
 * Return: nothing
 */

void free_tokenizer(void)
{
	int z = 0;

	if (mos->s == NULL)
		return;

	while (mos->s[z])
	{
		free(mos->s[z]);
		z++;
	}
	free(mos->s);
	mos->s = NULL;
}
