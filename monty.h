#ifndef _MONTY_H_
#define _MONTY_H_

#define SIZE 50

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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
 * struct global_s - global structure
 * @number: number
 * @file: file
 * @buf: buffer
 * @stack: stack
 */
typedef struct global_s
{
	char *number;
	FILE *file;
	char *buf;
	stack_t *stack;
	int is_stack;
} global_t;

extern global_t s;

void (*get_op_func(char *, unsigned int))(stack_t **stack, unsigned int);
void read_file(char *, stack_t *);
void free_stack(stack_t *);
char *_itoa(int n);
void free_global(void);
void check_number(unsigned int);
void op_pall(stack_t **, unsigned int);
void op_push(stack_t **, unsigned int);
void op_pint(stack_t **, unsigned int);
void op_swap(stack_t **, unsigned int);
void op_pchar(stack_t **, unsigned int);
void op_stack(stack_t **, unsigned int);
void op_queue(stack_t **, unsigned int);
void op_pstr(stack_t **, unsigned int);
void op_rotl(stack_t **, unsigned int);
void op_rotr(stack_t **, unsigned int);
void op_add(stack_t **, unsigned int);
void op_sub(stack_t **, unsigned int);
void op_mul(stack_t **, unsigned int);
void op_div(stack_t **, unsigned int);
void op_mod(stack_t **, unsigned int);
void op_pop(stack_t **, unsigned int);
void op_nop(stack_t **, unsigned int);
void queue_push(stack_t **, int);

#endif
