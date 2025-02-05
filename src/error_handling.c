/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:14:22 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 16:33:10 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*prev;

	if (stack)
	{
		current = *stack;
		while (current != NULL)
		{
			free(current->node);
			prev = current;
			current = current->next;
			free(prev);
		}
		*stack = NULL;
	}
}

int	error_syntax(char *string)
{
	while (*string == ' ' || *string == '\t' || *string == '\v'
		|| *string == '\r' || *string == '\f' || *string == '\n')
		++string;
	if (*string == '-' || *string == '+')
		++string;
	if (!ft_isdigit(*string))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (*string)
	{
		if (!ft_isdigit(*string))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		++string;
	}
	return (0);
}

int	error_duplicate(t_stack **stack, int n)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = *stack;
	while (current != NULL)
	{
		if (n == current->node->value)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		current = current->next;
	}
	return (0);
}
