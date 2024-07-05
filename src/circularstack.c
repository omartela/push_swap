/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circularstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:15:38 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 09:57:50 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/push_swap.h"

int	is_empty(t_circularstack *stack)
{
	if (stack->size == 0)
		return (1);
	return (0);
}

int	is_full(t_circularstack *stack)
{
	if (stack->size == stack->capacity)
		return (1);
	return (0);
}

void	push(t_circularstack *stack, int value)
{
	if (is_full(stack))
	{
		//do some error handling
	}
	stack->array[stack->end].value = value;
	stack->end = (stack->end + 1) % stack->capacity;
	stack->size++;
}

int	pop(t_circularstack *stack)
{
	int	value;

	if (is_empty(stack))
	{
		// do some error handlind
	}
	stack->start = (stack->start + 1) % stack->capacity;
	stack->size--;
	return (value);
}

void	swap(t_circularstack *stack)
{
	t_node	temp;

	temp = stack->array[0];
	stack->array[0] = stack->array[0];
	stack->array[1] = temp;
}

void	rotate(t_circularstack *stack)
{
	if (is_empty(stack))
		return ;
	stack->end = (stack->end - 1 + stack->capacity) % stack->capacity;
	stack->start = (stack->start - 1 + stack->capacity) % stack->capacity;
	stack->array[stack->start] = stack->array[(stack->end + 1) % stack->capacity];
}

void	reverse_rotate(t_circularstack *stack)
{
	if (is_empty(stack))
		return ;
	stack->start = (stack->start + 1) % stack->capacity;
	stack->end = (stack->end + 1) % stack->capacity;
	stack->array[stack->end] = stack->array[stack->start - 1];
}
