/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:34:47 by omartela          #+#    #+#             */
/*   Updated: 2024/07/15 10:59:32 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	set_median(t_stack **a)
{
	int		size;
	int		median;
	int		i;
	t_stack	*current;

	size = stack_size(*a);
	median = size / 2;
	current = *a;
	i = 0;
	while (current)
	{
		current->node->index = i;
		if (i <= median)
			current->node->above_median = 1;
		else
			current->node->above_median = 0;
		current = current->next;
		++i;
	}
}

void	set_target_a(t_stack **a, t_stack **b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_node	*target_node;
	long	best_value;

	current_a = *a;
	while (current_a != NULL)
	{
		current_b = *b;
		best_value = LONG_MIN;
		while (current_b != NULL)
		{
			if (current_b->node->value < current_a->node->value
				&& current_b->node->value > best_value)
			{
				target_node = current_b->node;
				best_value = current_b->node->value;
			}
			current_b = current_b->next;
		}
		if (best_value == LONG_MIN)
			current_a->node->target_node = find_max(b);
		else
			current_a->node->target_node = target_node;
		current_a = current_a->next;
	}
}

void	set_target_b(t_stack **a, t_stack **b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_node	*target_node;
	long	best_value;

	current_b = *b;
	while (current_b != NULL)
	{
		current_a = *a;
		best_value = LONG_MAX;
		while (current_a != NULL)
		{
			if (current_a->node->value > current_b->node->value
				&& current_a->node->value < best_value)
			{
				target_node = current_a->node;
				best_value = current_a->node->value;
			}
			current_a = current_a->next;
		}
		if (best_value == LONG_MAX)
			current_b->node->target_node = find_min(a);
		else
			current_b->node->target_node = target_node;
		current_b = current_b->next;
	}
}

void	calculate_push_cost_a(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_node	*node;
	int		size_a;
	int		size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	current = *a;
	while (current != NULL)
	{
		node = current->node;
		if (!node->above_median)
			node->push_cost = size_a - node->index;
		else
			node->push_cost = node->index;
		if (node->target_node->above_median)
			node->push_cost += node->target_node->index;
		else
			node->push_cost += size_b - (node->target_node->index);
		current = current->next;
	}
}

void	set_cheapest(t_stack **a)
{
	long	min_push_cost;
	t_node	*min_node;
	t_stack	*current;

	if (!a)
		return ;
	min_push_cost = LONG_MAX;
	current = *a;
	while (current)
	{
		min_node = current->node;
		if (current->node->push_cost < min_push_cost)
		{
			min_push_cost = current->node->push_cost;
			min_node = current->node;
		}
		current = current->next;
	}
	min_node->cheapest = 1;
}
