#include "monty.h"

/**
 * monty_comments - checks if there is a comment
 * Return: 1 or 0
 */

int monty_comments(void)
{
	if (mos->s && mos->s[0] && mos->s[0][0] == '#')
		return (1);
	return (0);
}
