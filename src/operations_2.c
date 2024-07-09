/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 23:06:02 by omartela          #+#    #+#             */
/*   Updated: 2024/07/09 09:13:21 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ra(t_circularstack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_circularstack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_circularstack *a, t_circularstack *b)
{
	rotate(a);
	rotate(b);
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
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
