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

	if (stack)
	{
		current = *stack;
		while (current != NULL)
		{
			free(current->node);
			current = current->next;
		}
		*stack = NULL;
	}
}

int	error_syntax(char *string)
{
	if (*string == '-' || *string == '+' || ft_isdigit(*string))
	{
		++string;
		while (*string)
		{
			if (!ft_isdigit(*string))
				return (1);
			++string;
		}
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
			return (1);
		current = current->next;
	}
	return (0);
}
