/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:49:15 by omartela          #+#    #+#             */
/*   Updated: 2024/07/17 09:45:02 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static long	string_to_integer(const char *str, int sign)
{
	long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + sign * (*str - '0');
		++str;
	}
	return (result);
}

long	ft_atol(const char *str)
{
	long	atol;
	int		sign;

	sign = 1;
	atol = 0;
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
