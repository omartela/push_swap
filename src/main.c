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

void	print_a_stack(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current != NULL)
	{
		ft_printf("%d \n", current->node->value);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (init_stack_a(&a, argv + 1))
		return (1);
	if (is_sorted(&a))
	{
		if (stack_size(a) == 2)
			swap(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	print_a_stack(&a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
