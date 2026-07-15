/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 08:07:25 by esttina           #+#    #+#             */
/*   Updated: 2026/07/16 00:04:41 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_node **stack)
{
    t_node  *head;
    int     max;
    int     max_bits;

    head = *stack;
    max = head->index;
    max_bits = 0;

    while(head)
    {
        if (head->index > max)
            max = head->index;
        head = head->next;
    }

    while ((max >> max_bits) != 0)
        max_bits++;
    
    return (max_bits);
}

void    radix_sort(t_node **stack_a, t_node **stack_b)
{
    t_node  *head_a;
    int     i;
    int     j;
    int     size;
    int     max_bits;

    size = ft_lstsize(*stack_a);
    max_bits = get_max_bits(stack_a);
    i = 0;
    while(i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            head_a = *stack_a;
            if (((head_a->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while(ft_lstsize(*stack_b) != 0)
            pa(stack_a, stack_b);
        i++;
    }
}