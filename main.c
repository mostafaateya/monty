#include "monty.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

char **operational_str = NULL;
s_data_s mos;

/**
 * main - main program
 * @argc: the count of arguments
 * @argv: pointer to array of char
 * Return: exit success or exit failure
 */

int main(int argc, char **argv)
{
	FILE *xxx = NULL;
	int _exit = EXIT_SUCCESS;

	if (argc != 2)
		return (monty_error_for_usage());
	xxx = fopen(argv[1], "r");
	if (xxx == NULL)
		return (monty_error_for_file_opening(argv[1]));
	_exit = monty_func_for_run(xxx);
	fclose(xxx);
	return (_exit);
}
