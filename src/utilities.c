/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:56:19 by omartela          #+#    #+#             */
/*   Updated: 2024/07/15 10:04:25 by omartela         ###   ########.fr       */
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

t_node	*find_max(t_stack **stack)
{
	t_node	*max;
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = *stack;
	max = current->node;
	while (current)
	{
		if (current->node->value > max->value)
			max = current->node;
		current = current->next;
	}
	return (max);
}

int	sort_three(t_stack **stack)
{
	t_node	*max;
	t_stack	*current;

	max = find_max(stack);
	current = *stack;
	if (current->node == max)
	{
		ra(stack);
		if ((*stack)->node->value > (*stack)->next->node->value)
			sa(stack);
	}
	else if (current->next->node == max)
	{
		rra(stack);
		if ((*stack)->node->value > (*stack)->next->node->value)
			sa(stack);
	}
	else if (current->next->next->node == max)
	{
		if ((*stack)->node->value > (*stack)->next->node->value)
			sa(stack);
	}
	return (0);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (!(stack && *stack && (*stack)->next))
		return (0);
	prev = *stack;
	current = prev->next;
	while (current)
	{
		if (prev->node->value > current->node->value)
			return (1);
		prev = current;
		current = current->next;
	}
	return (0);
}

t_node	*find_min(t_stack **stack)
{
	t_node	*min;
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = *stack;
	min = current->node;
	while (current)
	{
		if (current->node->value < min->value)
			min = current->node;
		current = current->next;
	}
	return (min);
}
