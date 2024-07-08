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
		stack->array = ft_realloc(stack->array, stack->capacity * sizeof(t_node), new_capacity * sizeof(t_node));
	if (!stack->array)
	{
		free_stack(stack);
		return (0);
	}
	stack->capacity = new_capacity;
	stack->end += (stack->end + 1) % stack->capacity;
	node.value = n;
	stack->array[stack->end] = node;
	node.index = stack->end;
	stack->size++;
	return (1);
}

int	init_stack(t_circularstack *stack)
{
	stack->array = (t_node *)malloc(1 * sizeof(t_node));
	stack->start = 0;
	stack->end = 0;
	stack->size = 0;
	stack->capacity = 0;
	return (1);
}

void	init_stack_a(t_circularstack *stack, char **str)
{
	long	n;
	int		i;

	i = 0;
	while (str[i])
	{
		if (error_syntax(str[i]))
		{
			free_stack(stack);
			return ;
		}
		n = ft_atoi(str[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_stack(stack);
			return ;
		}
		if (error_duplicate(stack, n))
		{
			free_stack(stack);
			return ;
		}
		add_node(stack, (int)n);
		i++;
	}
}
