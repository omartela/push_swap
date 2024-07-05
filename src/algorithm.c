/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:06:23 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 22:57:27 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	set_median(t_circularstack *a)
{
	int	i;
	int	median;

	median = a->size / 2;
	while (i < a->end)
	{
		if (i <= median)
			a->array[i].above_median = 1;
		else
			a->array[i].above_median = 0;
	}
}

static void	set_target_a(t_circularstack *a, t_circularstack *b)
{
	t_node	current;
	t_node	target_node;
	int		i;
	int		j;
	long	best_value;

	best_value = LONG_MIN;
	i = 0;
	while (i < a->end)
	{
		j = 0;
		best_value = LONG_MIN;
		current = b->array[j];
		while (j < b->end)
		{
			if (current.value < a->array[i].value
				&& current.value > best_value)
			{
				target_node = current;
				best_value = current.value;
			}
			j++;
		}
		if (best_value == LONG_MIN)
			a->array[i].target_node = find_max(b);
		else
			a->array[i].target_node = &target_node;
		i++;
	}
}

void	calculate_push_cost_a(t_circularstack *a, t_circularstack *b)
{
	int	i;

	i = 0;
	while (i < a->end)
	{
		if (!a->array[i].above_median)
			a->array[i].push_cost = a->size - a->array[i].index;
		if (a->array[i].target_node->above_median)
			a->array[i].push_cost += a->array[i].target_node->index;
		else
			a->array[i].push_cost += a->size - (a->array[i].target_node->index);
		i++;
	}
}

void	set_cheapest(t_circularstack *a)
{
	long	min_push_cost;
	int		i;
	t_node	min_node;

	if (is_empty(a))
		return ;
	i = 0;
	min_push_cost = LONG_MAX;
	while (i < a->end)
	{
		if (a->array[i].push_cost < min_push_cost)
		{
			min_push_cost = a->array[i].push_cost;
			min_node = a->array[i];
		}
	}
	min_node.cheapest = 1;
}

void	init_nodes_a(t_circularstack *a, t_circularstack *b)
{
	set_median(a);
	set_median(b);
	set_target_a(a, b);
	calculate_push_cost_a(a, b);
	set_cheapest(a);
}

void	move_stack_a_to_b(t_circularstack *a, t_circularstack *b)
{

}

void	sort_stacks(t_circularstack *a, t_circularstack *b)
{
	int	i;

	i = 0;
	if (a->size > 3 && !is_sorted(a))
		pb(b, a);
	if (a->size > 3 && !is_sorted(a))
		pb(b, a);
	while (a->size > 3 && !is_sorted(a))
	{
		init_nodes_a(a, b);
		move_stack_a_to_b(a, b);
	}
	sort_three(a);
	while (i < a->end)
	{

	}
}
