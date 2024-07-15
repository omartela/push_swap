/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedliststack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:15:38 by omartela          #+#    #+#             */
/*   Updated: 2024/07/15 10:06:04 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	push(t_stack **stack, t_stack *stack_node)
{
	stack_node->next = *stack;
	*stack = stack_node;
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*top;

	top = *stack;
	if (*stack == NULL)
		return (NULL);
	*stack = top->next;
	return (top);
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*new_first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	new_first = first->next;
	last = last_stack(*stack);
	first->next = NULL;
	last->next = first;
	*stack = new_first;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

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
