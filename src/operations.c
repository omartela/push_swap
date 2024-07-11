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

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa \n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb \n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss \n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*stack_node;

	stack_node = pop(b);
	push(a, stack_node);
	ft_printf("pa \n");
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*stack_node;

	if (b || a)
		return ;

	stack_node = pop(a);
	push(b, stack_node);
	ft_printf("pb \n");
}
