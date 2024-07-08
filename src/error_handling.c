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

void	free_stack(t_circularstack *stack)
{
	free(stack->array);
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

int	error_duplicate(t_circularstack *stack, int n)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (i < stack->size)
	{
		if (n == stack->array[i].value)
			return (1);
		++i;
	}
	return (0);
}
