#include "monty.h"

/**
 * seperate_str - seperates a string into words
 * @a: string to be seperated
 * @s: deleimiter characters
 * Return: array of pointer to each word
 */

char **seperate_str(char *a, char *s)
{
	char **aa = NULL;
	int count, l, y, z = 0;

	count = count_of_word(a, s);
	if (count == 0)
		return (NULL);
	aa = malloc((count + 1) * sizeof(char *));
	if (aa == NULL)
		return (NULL);
	while (z < count)
	{
		l = length_of_word(a, s);
		if (is_delim(*a, s))
			a = the_next_word(a, s);
		aa[z] = malloc((l + 1) * sizeof(char));
		if (aa[z] == NULL)
		{
			while (z >= 0)
			{
				z--;
				free(aa[z]);
			}
			free(aa);
			return (NULL);
		}
		y = 0;
		while (y < l)
		{
			aa[z][y] = *(a + y);
			y++;
		}
		aa[z][y] = '\0';
		a = the_next_word(a, s);
		z++;
	}
	aa[z] = NULL;
	return (aa);
}

/**
 * is_delim - checks if a string has delimeter character
 * @c: delimeter character
 * @s: deleimeter characters
 * Return: 1 if success or 0 if failure
 */

int is_delim(char c, char *s)
{
	int z = 0;

	while (s[z])
	{
		if (s[z] == c)
			return (1);
		z++;
	}
	return (0);
}

/**
 * length_of_word - gets the length of a word
 * @a: string input
 * @s: delimeter characters
 * Return: the length of word
 */

int length_of_word(char *a, char *s)
{
	int l = 0, x = 1, z = 0;

	while (*(a + z))
	{
		if (is_delim(a[z], s))
			x = 1;
		else if (x)
			l++;
		if (l > 0 && is_delim(a[z], s))
			break;
		z++;
	}
	return (l);
}

/**
 * count_of_word - gets the count of words in a string
 * @a: string input
 * @s: delimeter characters
 * Return: the count of words
 */

int count_of_word(char *a, char *s)
{
	int count = 0, x = 1, z = 0;

	while (*(a + z))
	{
		if (is_delim(a[z], s))
			x = 1;
		else if (x)
		{
			x = 0;
			count++;
		}
		z++;
	}
	return (count);
}

/**
 * the_next_word - gets the next word in a string
 * @a: string input
 * @s: delimeter characters
 * Return: pointer to the next word
 */

char *the_next_word(char *a, char *s)
{
	int x = 0, z = 0;

	while (*(a + z))
	{
		if (is_delim(a[z], s))
			x = 1;
		else if (x)
			break;
		z++;
	}
	return (a + z);
}
