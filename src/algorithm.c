/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:06:23 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 12:17:48 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	set_median(t_circularstack *a)
{
	int	i;
	int	median;

	i = 0;
	median = a->size / 2;
	while (i < a->size)
	{
		a->array[i].index = i;
		if (i <= median)
			a->array[i].above_median = 1;
		else
			a->array[i].above_median = 0;
		++i;
	}
}

static void	set_target_a(t_circularstack *a, t_circularstack *b)
{
	t_node	*current;
	t_node	*target_node;
	int		i;
	int		j;
	long	best_value;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		best_value = LONG_MIN;
		target_node = NULL;
		while (j < b->size)
		{
			current = &b->array[j];
			if (current->value < a->array[i].value
				&& current->value > best_value)
			{
				target_node = current;
				best_value = current->value;
			}
			j++;
		}
		if (target_node == NULL)
			a->array[i].target_node = find_max(b);
		else
			a->array[i].target_node = target_node;
		i++;
	}
}

static void	set_target_b(t_circularstack *a, t_circularstack *b)
{
	t_node	*current;
	t_node	*target_node;
	int		i;
	int		j;
	long	best_value;

	i = 0;
	while (i < b->size)
	{
		j = 0;
		best_value = LONG_MAX;
		while (j < a->size)
		{
			current = &a->array[j];
			if (current->value > b->array[i].value
				&& current->value < best_value)
			{
				target_node = current;
				best_value = current->value;
			}
			j++;
		}
		if (best_value == LONG_MAX)
			b->array[i].target_node = find_min(a);
		else
			b->array[i].target_node = target_node;
		i++;
	}
}

void	calculate_push_cost_a(t_circularstack *a, t_circularstack *b)
{
	int	i;

	i = 0;
	while (i < a->size)
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
	while (i < a->size)
	{
		a->array[i].cheapest = 0;
		if (a->array[i].push_cost < min_push_cost)
		{
			min_push_cost = a->array[i].push_cost;
			min_node = a->array[i];
		}
		++i;
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

t_node	*get_cheapest_node(t_circularstack *a)
{
	int		i;
	t_node	*cheapest;

	i = 0;
	cheapest = NULL;
	while (i < a->size)
	{
		if (a->array[i].cheapest == 1)
			*cheapest = a->array[i];
		++i;
	}
	return (cheapest);
}

void	prepare_for_push(t_circularstack *stack, t_node *cheapest)
{
	while (stack->array[stack->start].value != cheapest->value)
	{
		if (cheapest->above_median)
			rotate(stack);
		else
			reverse_rotate(stack);
	}
}

void	rotate_both(t_circularstack *a, t_circularstack *b, t_node *cheapest)
{
	while (a->array[a->start].value != cheapest->value
		&& b->array[b->start].value != cheapest->target_node->value)
	{
		rotate(a);
		rotate(b);
	}
	set_median(a);
	set_median(b);
}

void	rev_rotate_both(t_circularstack *a, t_circularstack *b, t_node *cheapest)
{
	while (a->array[a->start].value != cheapest->value
		&& b->array[b->start].value != cheapest->target_node->value)
	{
		rotate(a);
		rotate(b);
	}
	set_median(a);
	set_median(b);
}

void	move_node_a_to_b(t_circularstack *a, t_circularstack *b)
{
	t_node	*cheapest;

	cheapest = get_cheapest_node(a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		rev_rotate_both(a, b, cheapest);
	prepare_for_push(a, cheapest);
	push(b, a->array[b->start]);
}

void	init_nodes_b(a, b)
{
	set_median(a);
	set_median(b);
	set_target_b(a, b);
}

void	move_node_b_to_a(t_circularstack *a, t_circularstack *b)
{
	prepare_for_push(a, &b->array[b->start]);
	push(a, b->array[b->start]);
}

void	set_min_on_top(t_circularstack *a)
{
	while (a->array[a->start] != find_min(a))
	{
		if (find_min(a)->above_median)
			rotate(a);
		else
			reverse_rotate(a);
	}
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
		move_node_a_to_b(a, b);
	}
	sort_three(a);
	while (i < a->end)
	{
		init_nodes_b(a, b);
		move_node_b_to_a(a, b);
	}
	set_median(a);
	set_min_to_top(a);
}
