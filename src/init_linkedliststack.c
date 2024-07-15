/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linkedliststack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:15:08 by omartela          #+#    #+#             */
/*   Updated: 2024/07/15 11:03:07 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	add_stack_node(t_stack **stack, int value)
{
	t_stack	*new_stack_node;
	t_stack	*last;

	new_stack_node = create_stack_node(value);
	if (!new_stack_node)
		return (1);
	if (*stack == NULL)
		*stack = new_stack_node;
	else
	{
		last = last_stack(*stack);
		last->next = new_stack_node;
	}
	return (0);
}

t_stack	*create_stack_node(int value)
{
	t_node	*node;
	t_stack	*stack_node;

	stack_node = (t_stack *)malloc(sizeof(t_stack));
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->push_cost = 0;
	node->cheapest = 0;
	node->above_median = 0;
	node->target_node = NULL;
	if (!stack_node)
	{
		free(node);
		return (NULL);
	}
	stack_node->node = node;
	stack_node->next = NULL;
	return (stack_node);
}

int	check_argument(char **str, int i, t_stack **stack, long *n)
{
	if (error_syntax(str[i]))
	{
		free_stack(stack);
		return (1);
	}
	*n = ft_atol(str[i]);
	if (*n > INT_MAX || *n < INT_MIN)
	{
		free_stack(stack);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (error_duplicate(stack, *n))
	{
		free_stack(stack);
		return (1);
	}
	return (0);
}

int	init_stack_a(t_stack **stack, char **str)
{
	long	n;
	int		i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (check_argument(str, i, stack, &n))
			return (1);
		if (add_stack_node(stack, (int)n))
		{
			free_stack(stack);
			return (1);
		}
		i++;
	}
	return (0);
}
