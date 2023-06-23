#include "monty.h"

/**
 * pointer_to_int - gets a character pointer to string containing int
 * @x: number to be converted to string
 * Return: pointer to new string
 */

char pointer_to_int(int x)
{
	unsigned int t;
	int m = 0;
	long x1 = 0;
	char *a;

	t = int_absolute(x);
	m = buffer_length(t, 10);
	if (x < 0 || x1 < 0)
		m++;
	a = malloc(m + 1);
	if (!a)
		return (NULL);
	set_num(t, 10, a, m);
	if (x < 0 || x1 < 0)
		a[0] = '-';
	return (a);
}

/**
 * int_absolute - gets the absolute value of integer
 * @x: number needed
 * Return: unsigned int num
 */

unsigned int int_absolute(int x)
{
	if (x < 0)
		return (-(unsigned int)x);
	return ((unsigned int)x);
}

/**
 * buffer_length - gets the length of a buffer needed for unsigned int
 * @x: number needed
 * @z: base of number needed
 * Return: length of buffer needed
 */

int buffer_length(unsigned int x, unsigned int z)
{
	int m = 1;

	while (x > z - 1)
	{
		m++;
		x /= z;
	}
	return (m);
}

/**
 * set_num - fills the buffer with correct numbers
 * @x: number needed
 * @z: base of number needed
 * @a: the output string
 * @len: the buffer size in bytes
 * Return: nothing
 */

void set_num(unsigned int x, unsigned int z,
		char *a, int len)
{
	int m, n = len - 1;

	a[len] = '\0';
	while (n >= 0)
	{
		m = x % z;
		if (m > 0)
			a[n] = m + 87;
		else
			a[n] = m + '0';
		x /= z;
		n--;
	}
}
