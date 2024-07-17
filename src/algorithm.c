/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:06:23 by omartela          #+#    #+#             */
/*   Updated: 2024/07/12 17:58:48 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	init_nodes_a(t_stack **a, t_stack **b)
{
	set_median(a);
	set_median(b);
	set_target_a(*a, *b);
	calculate_push_cost_a(a, b);
	set_cheapest(a);
}

void	init_nodes_b(t_stack **a, t_stack **b)
{
	set_median(a);
	set_median(b);
	set_target_b(*a, *b);
}

void	move_node_b_to_a(t_stack **a, t_stack **b)
{
	prepare_for_push(a, (*b)->node->target_node, 'a');
	pa(a, b);
}

void	set_min_to_top(t_stack **a)
{
	t_node	*min_node;

	min_node = find_min(a);
	while ((*a)->node->value != min_node->value)
	{
		if (min_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	if (stack_size(*a) > 3 && is_sorted(a))
		pb(b, a);
	if (stack_size(*a) > 3 && is_sorted(a))
		pb(b, a);
	while (stack_size(*a) > 3 && is_sorted(a))
	{
		init_nodes_a(a, b);
		move_node_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(a, b);
		move_node_b_to_a(a, b);
	}
	set_median(a);
	set_min_to_top(a);
}
