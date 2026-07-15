/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 07:40:55 by esttina           #+#    #+#             */
/*   Updated: 2026/07/16 00:04:57 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    swap(t_node **stack)
{
    t_node  *first;
    t_node  *second;
    
    if (!stack || !*stack || !(*stack)->next)
        return ;

    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;

    *stack = second;
}

void    sa(t_node **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void    sb(t_node **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void    ss(t_node **stack_a, t_node **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}
