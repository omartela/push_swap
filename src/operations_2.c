/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 23:06:02 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 23:10:09 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ra(t_circularstack *a)
{
}

void	rb(t_circularstack *b)
{
}

void	rr(t_circularstack *a, t_circularstack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_circularstack *a)
{
	reverse_rotate(a);
}

void	rrb(t_circularstack *b)
{
	reverse_rotate(b);
}

void	rrr(t_circularstack *a, t_circularstack *b)
{
	rra(a);
	rrb(b);
}
