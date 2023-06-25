#include "monty.h"

/**
 * free_all_memory - frees the whole memory reserved for task
 * Return: nothing
 */

void free_all_memory(void)
{
	closing_file();
	free_tokenizer();
	free_data_stack();
}
