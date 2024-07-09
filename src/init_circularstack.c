/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_circularstack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:15:08 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 16:35:53 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	add_node(t_circularstack *stack, int n)
{
	int		new_capacity;
	t_node	node;

	new_capacity = stack->capacity + 1;
	if (stack->size == stack->capacity)
	{
		stack->array = ft_realloc(stack->array, stack->capacity * sizeof(t_node), new_capacity * sizeof(t_node));
		stack->capacity = new_capacity;
	}
	if (!stack->array)
	{
		free_stack(stack);
		return (0);
	}
	stack->end = (stack->end + 1) % stack->capacity;
	node.value = n;
	stack->array[stack->end] = node;
	node.index = stack->end;
	stack->size++;
	return (1);
}

void	init_stack(t_circularstack *stack)
{
	stack->array = NULL;
	stack->start = 0;
	stack->end = 0;
	stack->size = 0;
	stack->capacity = 0;
}

void	init_stack_b(t_circularstack *a, t_circularstack *b)
{
	b->array = malloc(a->capacity * sizeof(t_node));
	if (!b->array)
		free_stack(a);
	else
		b->capacity = a->capacity;
}

int	init_stack_a(t_circularstack *stack, char **str)
{
	long	n;
	int		i;

	i = 0;
	while (str[i])
	{
		if (error_syntax(str[i]))
		{
			free_stack(stack);
			return (1);
		}
		n = ft_atoi(str[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_stack(stack);
			return (1);
		}
		if (error_duplicate(stack, n))
		{
			free_stack(stack);
			return (1);
		}
		add_node(stack, (int)n);
		i++;
	}
	return (0);
}
