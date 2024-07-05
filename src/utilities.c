/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:56:19 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 10:08:54 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static int	string_to_integer(const char *str, int sign)
{
	long int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + sign * (*str - '0');
		++str;
	}
	return (result);
}

int	ft_atol(const char *str)
{
	int	atol;
	int	sign;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\f' || *str == '\n')
	{
		++str;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		++str;
	}
	atol = string_to_integer(str, sign);
	return (atol);
}

int	sort_three(t_circularstack *stack)
{
	t_node	max;
	int		i;

	i = 1;
	max = stack->array[0];
	while (i < stack->end)
	{
		if (stack->array[i - 1].value > max.value)
			max = stack->array[i - 1];
	}
	if (max.index == 0)
		rotate(stack);
	if (max.index == 1)
		reverse_rotate(stack);
	if (stack->array[0].value > stack->array[1].value)
		swap(stack);
	return (1);
}

int	is_sorted(t_circularstack *stack)
{
	int	i;

	i = 1;
	if (is_empty(stack))
		return (1);
	while (i < stack->end)
	{
		if (stack->array[i - 1].value > stack->array[i].value)
			return (0);
	}
	return (1);
}

t_node	*find_min(t_circularstack *stack)
{
	t_node	*min;
	int		i;

	if (is_empty(stack))
		return (NULL);
	i = 1;
	*min = stack->array[0];
	while (i < stack->end)
	{
		if (stack->array[i - 1].value < min->value)
			*min = stack->array[i - 1];
		i++;
	}
	return (min);
}
