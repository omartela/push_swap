/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:56:19 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 16:57:55 by omartela         ###   ########.fr       */
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

t_node	*find_max(t_circularstack *stack)
{
	int		i;
	t_node	*max;

	max = NULL;
	max = &stack->array[stack->start];
	i = stack->start;
	while (i <= stack->end)
	{
		if (stack->array[i].value > max->value)
			max = &stack->array[i];
		++i;
	}
	return (max);
}

int	sort_three(t_circularstack *stack)
{
	t_node	*max;
	t_node	*start;

	max = find_max(stack);
	start = &stack->array[stack->start];

	if (max == start)
	{
		ra(stack);
		if (stack->array[stack->start].value > stack->array[(stack->start + 1) % stack->capacity].value)
			sa(stack);
	}
	else if (max == &stack->array[(stack->start + 1) % stack->capacity])
	{
		rra(stack);
		if (stack->array[stack->start].value > stack->array[(stack->start + 1) % stack->capacity].value)
			sa(stack);
	}
	else if (max == &stack->array[(stack->start + 2) % stack->capacity])
	{
		if (stack->array[stack->start].value > stack->array[(stack->start + 1) % stack->capacity].value)
			sa(stack);
	}
	return (1);
}


int	is_sorted(t_circularstack *stack)
{
	int	i;

	i = stack->start + 1;
	if (is_empty(stack))
		return (1);
	while (i <= stack->end)
	{
		if (stack->array[i - 1].value > stack->array[i].value)
			return (0);
		++i;
	}
	return (1);
}

t_node	*find_min(t_circularstack *stack)
{
	t_node	*min;
	int		i;

	i = stack->start;
	if (is_empty(stack))
		return (NULL);
	min = &stack->array[stack->start];
	while (i <= stack->end)
	{
		if (stack->array[i].value < min->value)
			min = &stack->array[i];
		i++;
	}
	return (min);
}
