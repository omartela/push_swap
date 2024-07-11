/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circularstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:15:38 by omartela          #+#    #+#             */
/*   Updated: 2024/07/11 09:18:58 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_stack	*last_stack(t_stack *stack)
{
	if (stack)
	{
		while (stack->next != 0)
			stack = stack->next;
		return (stack);
	}
	return (NULL);
}

int	stack_size(t_stack *stack)
{
	int	n_nodes;

	if (!stack)
		return (0);
	n_nodes = 0;
	while (stack != 0)
	{
		stack = stack->next;
		n_nodes = n_nodes + 1;
	}
	return (n_nodes);
}

void	push(t_stack **stack, t_stack *stack_node)
{
	stack_node->next = *stack;
	*stack = stack_node;
}

t_stack *pop(t_stack **stack)
{
    t_stack  *top;

    top = *stack;
    if (*stack == NULL) 
        return NULL;

    *stack = top->next;
    return (top);
}

void swap(t_stack **stack) 
{
    if (*stack == NULL || (*stack)->next == NULL) 
    {
        // Handle error: not enough elements to swap
        return;
    }
    t_stack *first = *stack;
    t_stack *second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}


void rotate(t_stack **stack) 
{
    t_stack  *first;
    t_stack  *last;
    t_stack  *new_first;

    if (*stack == NULL || (*stack)->next == NULL) 
        return ;
    first = *stack;
    new_first = first->next;
    last = last_stack(*stack);
    first->next = NULL;
    last->next = first;
    *stack = new_first;
}

void reverse_rotate(t_stack **stack) 
{
    t_stack *second_last;
    t_stack *last;

    if (*stack == NULL || (*stack)->next == NULL) 
        return ;
    second_last = *stack;
    while (second_last->next->next != NULL) 
        second_last = second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

