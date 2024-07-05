/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:06:23 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 11:27:13 by omartela         ###   ########.fr       */
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

static	void set_target_a(t_circularstack *a, t_circularstack *b)
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

void	init_nodes_a(t_circularstack *a, t_circularstack *b)
{
	set_median(a);
	set_median(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
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
	}
	sort_three(a);
	while (i < a->end)
	{
	}
}
