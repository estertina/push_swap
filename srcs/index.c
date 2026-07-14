/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 05:19:48 by esttina           #+#    #+#             */
/*   Updated: 2026/07/14 07:16:25 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void index_stack(t_node **stack)
{
	t_node	*head;
	t_node	*highest;
	int		size;

	size = ft_lstsize(*stack);

	// Keep looping until we've assigned an index to every node
    while (size > 0)
    {
        head = *stack;
        highest = NULL;

        // Walk through the list to find the highest undindexed value
        while (head != NULL)
        {
            if (head->index == -1 && (highest == NULL || head->value > highest->value))
                highest = head;
            head = head->next;
        }

        // Assign the rank, and decrement size for the next loop
        if (highest != NULL)
            highest->index = size - 1;
        size--;
    }
}