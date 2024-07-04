/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_circularstack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:53:38 by omartela          #+#    #+#             */
/*   Updated: 2024/07/04 16:56:01 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	init_stack(t_circularstack *stack, int capacity)
{
	stack->array = (int *)malloc(capacity * sizeof(int));
	if (!stack->array)
		return (0);
	stack->start = 0;
	stack->end = 0;
	stack->size = 0;
	stack->capacity = 0;
	return (1);
}
