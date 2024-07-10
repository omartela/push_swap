/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_circularstack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:15:08 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 16:35:53 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list *create_node(int value) 
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->index = 0;
    node->push_cost = 0;
    node->cheapest = 0;
    node->above_median = 0;
    node->target_node = NULL;

    t_list *list_node = malloc(sizeof(t_list));
    if (!list_node) {
        free(node);
        return NULL;
    }
    list_node->node = node;
    list_node->next = NULL;
	list_node->prev = NULL;

    return (list_node);
}


void	init_stack(t_circularstack *stack)
{
	stack->array = NULL;
	stack->start = 0;
	stack->end = 0;
	stack->size = 0;
	stack->capacity = 0;
}

void	init_stack_b(t_circularstack *a, t_circularstack *b)
{
	b->array = malloc(a->capacity * sizeof(t_node));
	if (!b->array)
		free_stack(a);
	else
		b->capacity = a->capacity;
}

int	init_stack_a(t_circularstack *stack, char **str)
{
	long	n;
	int		i;
// muista free split stack
	i = 0;
	while (str[i])
	{
		if (error_syntax(str[i]))
		{
			free_stack(stack);
			return (1);
		}
		n = ft_atoi(str[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_stack(stack);
			return (1);
		}
		if (error_duplicate(stack, n))
		{
			free_stack(stack);
			return (1);
		}
		add_node(stack, (int)n);
		i++;
	}
	return (0);
}
