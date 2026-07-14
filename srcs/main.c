/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:42:18 by esttina           #+#    #+#             */
/*   Updated: 2026/07/14 12:11:20 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_node **stack_a, int ac, char **av)
{
	t_node	*new_node;
	long	tmp;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (check_validity(av[i]))
			return (1);

		tmp = ft_atol(av[i]);
		if (tmp > 2147483647 || tmp < -2147483648 || check_duplicate(*stack_a, (int)tmp));
			return (1);
		
		new_node = ft_lstnew((int)tmp);
		if (!new_node)
			return (1);
		
		ft_lstadd_back(stack_a, new_node);
		i++;

		return (0);
	}
}
int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (0);
		
	stack_a = NULL;
	stack_b = NULL;
	
	if (init_stack(&stack_a, ac, av) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}