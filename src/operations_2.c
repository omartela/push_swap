/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 23:06:02 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 09:57:12 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ra(t_circularstack *a)
{
	ra(a);
	ft_printf("ra\n");
}

void	rb(t_circularstack *b)
{
	rb(b);
	ft_printf("rb\n");
}

void	rr(t_circularstack *a, t_circularstack *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	rra(t_circularstack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_circularstack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_circularstack *a, t_circularstack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
