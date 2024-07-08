/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:49:54 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 13:03:14 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	int				cheapest;
	int				above_median;
	struct s_node	*target_node;
}	t_node;

typedef struct s_circularstack
{
	t_node	*array;
	int		start;
	int		end;
	int		size;
	int		capacity;
}	t_circularstack;

int		error_syntax(char *string);
int		error_duplicate(t_circularstack *stack, int n);
int		ft_atol(const char *str);
void	swap(t_circularstack *stack);
void	rotate(t_circularstack *stack);
void	reverse_rotate(t_circularstack *stack);
void	push(t_circularstack *stack, t_node *node);
t_node	pop(t_circularstack *stack);
int		is_empty(t_circularstack *stack);
int		is_full(t_circularstack *stack);
int		is_sorted(t_circularstack *stack);
int		sort_three(t_circularstack *stack);
t_node	*find_min(t_circularstack *stack);
t_node	*find_max(t_circularstack *stack);
void	sb(t_circularstack *b);
void	sa(t_circularstack *a);
void	ss(t_circularstack *a, t_circularstack *b);
void	pa(t_circularstack *a, t_circularstack *b);
void	pb(t_circularstack *a, t_circularstack *b);

#endif
