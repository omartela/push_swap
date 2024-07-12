/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:43:13 by omartela          #+#    #+#             */
/*   Updated: 2024/07/12 17:58:40 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_node	*get_cheapest_node(t_stack **a)
{
	t_stack	*current;

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
		{
			if (indicator == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (indicator == 'a')
				rra(stack);
			else
				rrb(stack);
		}
		current = *stack;
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_node *cheapest)
{
	t_stack	*current_a;
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
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = *a;
	current_b = *b;
	while (current_a->node->value != cheapest->value
		&& current_b->node->value != cheapest->target_node->value)
	{
		rrr(a, b);
		current_a = *a;
		current_b = *b;
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
