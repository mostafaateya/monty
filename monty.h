#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MOS_STACK 0
#define MOS_QUEUE 1
#define MOS_DELIMS " \n\t\a\b"

extern char **operational_str;

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
 * struct data_content  - opcode and its function
 * @op_func: the opcode
 * @value: function to handle the opcode
 * @i: number of the line
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct data_content
{
	char *op_func;
	char *value;
	int i ;
} data_t;

/**
 * struct stack_data - opcode and its function
 * @int_value: needed input.
 * @data: needed input.
 * @fp: needed input.
 * @line: needed iput.
 * Description: stack_data
 */
typedef struct stack_data
{
	int int_value;
	data_t data;
	FILE *fp;
	char *line;
} s_data_s;

extern s_data_s mos;

int monty_error_for_usage(void);
int monty_error_for_malloc(void);
int monty_error_for_file_opening(char *);
int monty_error_for_unkown_operation(char *, unsigned int);
int monty_error_for_invlaid_inputs(unsigned int);

int monty_error_for_pop(unsigned int);
int monty_error_for_pint(unsigned int);
int monty_error_for_small_stack(unsigned int, char *);
int monty_error_for_div(unsigned int);
int monty_error_for_pchar(unsigned int, char *);

char *pointer_to_int(int);
unsigned int int_absolute(int);
int buffer_length(unsigned int, unsigned int);
void set_num(unsigned int, unsigned int, char *, int);

void monty_func_for_push(stack_t **, unsigned int);
void monty_func_for_pall(stack_t **, unsigned int);
void monty_func_for_pint(stack_t **, unsigned int);
void monty_func_for_pop(stack_t **, unsigned int);
void monty_func_for_swap(stack_t **, unsigned int);

void monty_func_for_add(stack_t **, unsigned int);
void monty_func_for_sub(stack_t **, unsigned int);
void monty_func_for_div(stack_t **, unsigned int);
void monty_func_for_mul(stack_t **, unsigned int);
void monty_func_for_mod(stack_t **, unsigned int);

void monty_func_for_nop(stack_t **, unsigned int);
void monty_func_for_pchar(stack_t **, unsigned int);
void monty_func_for_pstr(stack_t **, unsigned int);

void monty_func_for_rotl(stack_t **, unsigned int);
void monty_func_for_rotr(stack_t **, unsigned int);
void monty_func_for_stack(stack_t **, unsigned int);
void monty_func_for_queue(stack_t **, unsigned int);

#endif
