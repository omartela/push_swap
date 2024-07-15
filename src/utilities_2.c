/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:05:40 by omartela          #+#    #+#             */
/*   Updated: 2024/07/15 10:06:39 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	n_nodes;

	if (!stack)
		return (0);
	n_nodes = 0;
	while (stack != 0)
	{
		stack = stack->next;
		n_nodes = n_nodes + 1;
	}
	return (n_nodes);
}
