#include "monty.h"

/**
 * m_pop - pop top element off of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_len != 1)
	{
		*stack = (*stack)->next;
	}
	else
	{
		*stack = NULL;
	}
	free(pop);
	var.stack_len--;
}

/**
 * m_swap - swap top two elements of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
	(*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
	next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}