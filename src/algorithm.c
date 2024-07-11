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

void	set_median(t_stack **a)
{
	int	size;
	int	median;
	int	i;
	t_stack	*current;

	size = stack_size(*a);
	median = size / 2;
	current = *a;
	i = 0;
	while (current->next)
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

static void	set_target_a(t_stack **a, t_stack **b)
{
	t_stack	*current_a;
	t_stack	*current_b;
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
			current_b = current_b->next;
		}
		if (target_node == NULL)
			current_a->node->target_node = find_max(b);
		else
			current_a->node->target_node = target_node;
		current_a = current_a->next;
	}
}

static void	set_target_b(t_stack **a, t_stack **b)
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

void	calculate_push_cost_a(t_stack **a)
{
	t_stack	*current;
	t_node	*node;
	int		size;

	size = stack_size(*a);
	current = *a;
	while (current != NULL)
	{
		node = current->node;
		if (!node->above_median)
			node->push_cost = size - node->index;
		if (node->target_node->above_median)
			node->push_cost += node->target_node->index;
		else
			node->push_cost += size - (node->target_node->index);
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

void	init_nodes_a(t_stack **a, t_stack **b)
{
	set_median(a);
	set_median(b);
	set_target_a(a, b);
	calculate_push_cost_a(a);
	set_cheapest(a);
}

t_node	*get_cheapest_node(t_stack **a)
{
	t_stack *current;

	current = *a;
	while (current != NULL)
	{
		if (current->node->cheapest == 1)
			return (current->node);
		current = current->next;
	}
	return (NULL);
}

void	prepare_for_push(t_stack **stack, t_node *cheapest, char indicator)
{
	t_stack	*current;

	current = *stack;
	while (current->node->value != cheapest->value)
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
		current = current->next;
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_node *cheapest)
{
	t_stack *current_a;
	t_stack	*current_b;

	current_a = *a;
	current_b = *b;
	while (current_a->node->value != cheapest->value
		&& current_b->node->value != cheapest->target_node->value)
	{
		rr(a, b);
		current_a = current_a->next;
		current_b = current_b->next;
	}
	set_median(a);
	set_median(b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_node *cheapest)
{
	t_stack *current_a;
	t_stack	*current_b;

	current_a = *a;
	current_b = *b;
	while (current_a->node->value != cheapest->value
		&& current_b->node->value != cheapest->target_node->value)
	{
		rrr(a, b);
		current_a = current_a->next;
		current_b = current_b->next;
	}
	set_median(a);
	set_median(b);
}

void	move_node_a_to_b(t_stack **a, t_stack **b)
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

void	init_nodes_b(t_stack **a, t_stack **b)
{
	set_median(a);
	set_median(b);
	set_target_b(a, b);
}

void	move_node_b_to_a(t_stack **a, t_stack **b)
{
	prepare_for_push(a, (*b)->node->target_node, 'a');
	pa(a, b);
}

void set_min_to_top(t_stack **a)
{
    t_node *min_node = find_min(a);

    while ((*a)->node->value != min_node->value)
    {
        if (min_node->above_median)
            ra(a);
        else
            rra(a);
    }
}


void sort_stacks(t_stack **a, t_stack **b)
{
    if (stack_size(*a) > 3 && !is_sorted(a))
        pb(b, a);
    if (stack_size(*a) > 3 && !is_sorted(a))
        pb(b, a);
    while (stack_size(*a) > 3 && !is_sorted(a))
    {
        init_nodes_a(a, b);
        move_node_a_to_b(a, b);
    }
    sort_three(a);
    while (stack_size(*b) > 0)
    {
        init_nodes_b(a, b);
        move_node_b_to_a(a, b);
    }
    set_median(a);
    set_min_to_top(a);
}
