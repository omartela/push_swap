/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:25:24 by omartela          #+#    #+#             */
/*   Updated: 2024/07/17 08:49:57 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	free_arguments(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}

int	check_arguments_and_init(t_stack **a, char **argv, int argc)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (*argv == NULL)
			ft_putstr_fd("Error\n", 2);
		if (init_stack_a(a, argv))
		{
			free_arguments(argv);
			return (1);
		}
		free_arguments(argv);
		return (0);
	}
	else
	{
		if (init_stack_a(a, argv + 1))
			return (1);
		return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (check_arguments_and_init(&a, argv, argc))
		return (1);
	if (is_sorted(&a) && stack_size(a) > 1)
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
