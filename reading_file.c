#include "monty.h"

/**
 * stream_message - prints a message for getting stream error
 * @ff: path file
 * Return: nothing
 */

void stream_message(char *ff)
{
	dprintf(2, "Error: Can't open file %s\n", ff);
	free_data_stack();
	exit(EXIT_FAILURE);
}

/**
 * reading_file - reads a file
 * @ff: path file
 * Return: nothing
 */

void reading_file(char *ff)
{
	int f;

	f = open(ff, O_RDONLY);
	if (f == -1)
		stream_message(ff);

	mos->ff = fdopen(f, "r");
	if (mos->ff == NULL)
	{
		close(f);
		 stream_message(ff);
	}
}
