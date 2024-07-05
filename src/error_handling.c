/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:14:22 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 06:56:57 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	error_syntax(char *string)
{
}

int	error_duplicate(t_circularstack *stack, t_node *node)
{
	int	i;

	i = 0;
	while (i < stack->end)
	{
		if (node->value == stack->array[i].value)
			return (1);
	}
	return (0);
}
