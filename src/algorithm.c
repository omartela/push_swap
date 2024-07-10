/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:06:23 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 15:10:54 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	set_median(t_list **a)
{
	int	size;
	int	median;
	t_list	*current;

	size = ft_lstsize(*a);
	median = size / 2;
	current = a;
	while (current->next)
	{
		current->node.index = i;
		if (i <= median)
			current->node.above_median = 1;
		else
			current->node.above_median = 0;
		current = current->next;
	}
}

static void	set_target_a(t_list **a, t_list **b)
{
	t_list	*current_a;
	t_list	*current_b;
	t_node	*target_node;
	t_node	*current_node_b;
	long	best_value;

	current_a = *a;
	while (current_a != NULL)
	{
		current_b = *b;
		best_value = LONG_MIN;
		target_node = NULL;
		while (current_b != NULL)
		{
			current_node_b = current_b->node;
			if (current_node_b->value < current_a->node->value
				&& current_node_b->value > best_value)
			{
				target_node = current_node_b;
				best_value = current_node_b->value;
			}

		}
		if (target_node == NULL)
			current_a->node->target_node = find_max(b);
		else
			current_a->node->target_node = target_node;
	}
}

static void	set_target_b(t_list **a, t_list **b)
{
	t_list	*current_a;
	t_list	*current_b;
	t_node	*target_node;
	t_node	*current_node_b;
	long	best_value;

	current_b = *b;
	while (current_b != NULL)
	{
		current_a = *a;
		best_value = LONG_MAX;
		while (current_a != NULL)
		{
			current_node_a = current_a->node;
			if (current_node_a->value > current_b->node->value
				&& current->value < best_value)
			{
				target_node = current_node_a;
				best_value = current_node_a->value;
			}
		}
		if (best_value == LONG_MAX)
			current_b->node->target_node = find_min(a);
		else
			current_b->node->target_node = target_node;
	}
}

void	calculate_push_cost_a(t_list **a)
{
	int	i;

	i = a->start;
	while (i <= a->end)
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
	t_node	*min_node;

	if (is_empty(a))
		return ;
	i = a->start;
	min_push_cost = LONG_MAX;
	while (i <= a->end)
	{
		a->array[i].cheapest = 0;
		if (a->array[i].push_cost < min_push_cost)
		{
			min_push_cost = a->array[i].push_cost;
			min_node = &a->array[i];
		}
		++i;
	}
	min_node->cheapest = 1;
}

void	init_nodes_a(t_circularstack *a, t_circularstack *b)
{
	set_median(a);
	set_median(b);
	set_target_a(a, b);
	calculate_push_cost_a(a);
	set_cheapest(a);
}

t_node	*get_cheapest_node(t_circularstack *a)
{
	int		i;
	t_node	*cheapest;

	i = a->start;
	cheapest = NULL;
	while (i <= a->end)
	{
		if (a->array[i].cheapest == 1 || cheapest == NULL)
			cheapest = &a->array[i];
		++i;
	}
	return (cheapest);
}

void	prepare_for_push(t_circularstack *stack, t_node *cheapest, char indicator)
{
	while (stack->array[stack->start].value != cheapest->value)
	{
		if (cheapest->above_median)
			if (indicator == 'a')
				ra(stack);
			else
				rb(stack);
		else
			if (indicator == 'a')
				rra(stack);
			else
				rrb(stack);
	}
}

void	rotate_both(t_circularstack *a, t_circularstack *b, t_node *cheapest)
{
	while (a->array[a->start].value != cheapest->value
		&& b->array[b->start].value != cheapest->target_node->value)
	{
		rr(a, b);
	}
	set_median(a);
	set_median(b);
}

void	rev_rotate_both(t_circularstack *a, t_circularstack *b, t_node *cheapest)
{
	while (a->array[a->start].value != cheapest->value
		&& b->array[b->start].value != cheapest->target_node->value)
	{
		rrr(a, b);
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
	prepare_for_push(a, cheapest, 'a');
	prepare_for_push(b, cheapest->target_node, 'b');
	pb(b, a);
}

void	init_nodes_b(t_circularstack *a, t_circularstack *b)
{
	set_median(a);
	set_median(b);
	set_target_b(a, b);
}

void	move_node_b_to_a(t_circularstack *a, t_circularstack *b)
{
	prepare_for_push(a, b->array[b->start].target_node, 'a');
	pa(a, b);
}

void	set_min_to_top(t_circularstack *a)
{
	while (a->array[a->start].value != find_min(a)->value)
	{
		if (find_min(a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_circularstack *a, t_circularstack *b)
{
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
	while (b->size > 0)
	{
		init_nodes_b(a, b);
		move_node_b_to_a(a, b);
	}
	set_median(a);
	set_min_to_top(a);
}
