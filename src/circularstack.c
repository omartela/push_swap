/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circularstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 06:15:38 by omartela          #+#    #+#             */
/*   Updated: 2024/07/08 15:03:59 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void push(t_list **stack, int value) {
    t_list *new_node = create_node(value);
    if (!new_node) {
        // Handle memory allocation error
        return;
    }
    new_node->next = *stack;
    *stack = new_node;
}

t_node *pop(t_list **stack) {
    if (*stack == NULL) 
	{
        // Handle error: stack is empty
        return NULL;
    }

    t_list *top = *stack;
    t_node *node = top->node;

    // Update the stack to point to the next node
    *stack = top->next;
    if (*stack != NULL) 
        (*stack)->prev = NULL;  // Set previous of the new head to NULL

    free(top);  // Free the memory of the popped node

    return (node);
}

void swap(t_list **stack) 
{
    if (*stack == NULL || (*stack)->next == NULL) {
        // Handle error: not enough elements to swap
        return;
    }
    t_list *first = *stack;
    t_list *second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}


void rotate(t_list **stack) 
{
    if (*stack == NULL || (*stack)->next == NULL) {
        // Handle error: not enough elements to rotate
        return;
    }
    t_list *first = *stack;
    t_list *last = ft_lstlast_bonus(stack);
    first->next = NULL;
	first->prev = last;
    last->next = first;
}

void reverse_rotate(t_list **stack) 
{
    if (*stack == NULL || (*stack)->next == NULL) {
        // Handle error: not enough elements to reverse rotate
        return;
    }
    // Find the last node
    last = ft_lstlast_bonus(stack);

    // Disconnect the last node
    if (last->prev != NULL) 
        last->prev->next = NULL;

    // Set the last node as the new head of the stack
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

