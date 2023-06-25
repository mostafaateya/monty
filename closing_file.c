#include "monty.h"

/**
 * closing_file - closes a file
 * Return: nothing
 */

void closing_file(void)
{
	if (mos == NULL)
		return;
	fclose(mos->ff);
	mos->ff = NULL;
}
