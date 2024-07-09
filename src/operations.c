/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 23:05:03 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 14:29:48 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	sa(t_circularstack *a)
{
	swap(a);
	ft_printf("sa \n");
}

void	sb(t_circularstack *b)
{
	swap(b);
	ft_printf("sb \n");
}

void	ss(t_circularstack *a, t_circularstack *b)
{
	sa(a);
	sb(b);
	ft_printf("ss \n");
	ft_printf("ss \n");
}

void	pa(t_circularstack *a, t_circularstack *b)
{
	t_node	*node;

	node = pop(b);
	push(a, node);
	ft_printf("pa \n");
}

void	pb(t_circularstack *b, t_circularstack *a)
{
	t_node	*node;

	node = pop(a);
	push(b, node);
	ft_printf("pb \n");
}
