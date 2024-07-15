/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:49:54 by omartela          #+#    #+#             */
/*   Updated: 2024/07/12 17:59:42 by omartela         ###   ########.fr       */
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

typedef struct s_stack
{
	t_node			*node;
	struct s_stack	*next;
}					t_stack;

int		stack_size(t_stack *stack);
t_stack	*create_stack_node(int value);
int		error_syntax(char *string);
int		error_duplicate(t_stack **stack, int n);
long	ft_atol(const char *str);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **stack, t_stack *stack_node);
t_stack	*pop(t_stack **stack);
int		is_sorted(t_stack **stack);
int		sort_three(t_stack **stack);
t_node	*find_min(t_stack **stack);
t_node	*find_max(t_stack **stack);
void	sb(t_stack **b);
void	sa(t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	init_stack(t_stack **stack);
int		init_stack_a(t_stack **stack, char **str);
void	sort_stacks(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
t_stack	*last_stack(t_stack *stack);
void	set_median(t_stack **a);
void	set_target_a(t_stack **a, t_stack **b);
void	set_target_b(t_stack **a, t_stack **b);
void	calculate_push_cost_a(t_stack **a);
void	set_cheapest(t_stack **a);
void	prepare_for_push(t_stack **stack, t_node *cheapest, char indicator);
void	move_node_a_to_b(t_stack **a, t_stack **b);

#endif
