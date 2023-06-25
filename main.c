#include "monty.h"

s_data_s *mos = NULL;

/**
 * main - main program
 * @argc: number of arguments
 * @argv: arrays of arguments
 * Return: 0 on Success
 */

int main(int argc, char **argv)
{
	size_t z = 0;

	check_argv(argc);
	define_mos();
	reading_file(argv[1]);

	while (getline(&mos->a, &z, mos->ff) != -1)
	{
		mos->x += 1;
		tokenizer();
		setting_for_instruction();
		monty_func_for_run();
		free_tokenizer();
	}
	closing_file();
	free_data_stack();
	return (0);
}
