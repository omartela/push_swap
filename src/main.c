/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:25:24 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 16:25:22 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	print_a_stack(t_circularstack *a)
{
	int i;

	i = a->start;
	while (i <= a->end)
	{
		ft_printf("%d \n", a->array[i].value);
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_circularstack	a;
	t_circularstack	b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack(&a);
	init_stack(&b);
	if (init_stack_a(&a, argv + 1))
		return (1);
	init_stack_b(&a, &b);
	if (!is_sorted(&a))
	{
		if (a.size == 2)
			swap(&a);
		else if (a.size == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	print_a_stack(&a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
