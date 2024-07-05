/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:14:22 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 08:43:02 by omartela         ###   ########.fr       */
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
		while (string)
		{
			if (!ft_isdigit(*string))
				return (1);
		}
	}
	return (0);
}

int	error_duplicate(t_circularstack *stack, int n)
{
	int	i;

	i = 0;
	while (i < stack->end)
	{
		if (n == stack->array[i].value)
			return (1);
	}
	return (0);
}
