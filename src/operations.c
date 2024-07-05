/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 23:05:03 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 23:20:37 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	sa(t_circularstack *a)
{
	swap(a);
}

void	sb(t_circularstack *b)
{
	swap(b);
}

void	ss(t_circularstack *a, t_circularstack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_circularstack *a, t_circularstack *b)
{
	push(a, b->array[0]);
}

void	pb(t_circularstack *a, t_circularstack *b)
{
	push(b, a->array[0]);
}
