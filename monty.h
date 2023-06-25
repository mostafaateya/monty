#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_stack - container for var
 * @ff: file to bo opened and read
 * @a: line text
 * @x: num of line to trrack
 * @s: store broken down tokens
 * @xt: uasable ins
 * @n: tokens num
 * @top: h
 * @nn: num of node in stack
 * @st: stack
 */
typedef struct data_stack
{
	FILE *ff;
	char *a;
	unsigned int x;
	char **s;
	int n;
	instruction_t *xt;
	stack_t *top;
	int nn;
	int st;
} s_data_s;

extern s_data_s *mos;

void monty_func_for_add(stack_t **, unsigned int);
void closing_file(void);
int monty_comments(void);
void top_element_delete(void);
void setting_for_instruction(void);
void monty_error_for_message(void);
void reading_file(char *);
void stream_message(char *);
void define_mos(void);
int validate_num(char *);
void monty_error_for_malloc(void);
void monty_func_for_nop(stack_t **, unsigned int);
void monty_func_for_push(stack_t **, unsigned int);
void monty_func_for_pall(stack_t **, unsigned int);
void monty_func_for_run(void);
void monty_func_for_pop(stack_t **, unsigned int);
void monty_func_for_pint(stack_t **, unsigned int);
void check_argv(int);
void tokenizer(void);
void monty_func_for_swap(stack_t **, unsigned int);

int dprintf(int, const char *, ...);
ssize_t getline(char **, size_t *, FILE *);
FILE *fdopen(int, const char *);

void free_mos(void);
void free_data_stack(void);
void free_all_memory(void);
void free_stack(stack_t *);
void free_tokenizer(void);

void monty_func_for_sub(stack_t **, unsigned int);
void monty_func_for_mul(stack_t **, unsigned int);
void monty_func_for_div(stack_t **, unsigned int);
void monty_func_for_mod(stack_t **, unsigned int);

#endif
