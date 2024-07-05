/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:49:54 by omartela          #+#    #+#             */
/*   Updated: 2024/07/05 07:48:15 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
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

#endif
