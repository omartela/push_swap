/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:06:23 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 10:21:12 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	sort_stacks(t_circularstack *a, t_circularstack *b)
{
	int i;

	i = 0;
	if (a->size > 3 && !is_sorted(a))
		pb(b, a);
	if (a->size > 3 && !is_sorted(a))
		pb(b, a);
	while (a->size > 3 && !is_sorted(a))
	{
	}
	sort_three(a);
	while (i < a->end)
	{
	}
}
