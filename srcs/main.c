/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:42:18 by esttina           #+#    #+#             */
/*   Updated: 2026/07/16 02:47:57 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	init_stack(t_node **stack, char **args)
{
	t_node	*new_node;
	long	tmp;
	int		i;

	i = 0;
	while (args[i])
	{
		if (check_validity(args[i]))
			return (1);
		tmp = ft_atol(args[i]);
		if (tmp > 2147483647 || tmp < -2147483648
			|| check_duplicate(*stack, (int)tmp))
			return (1);
		new_node = ft_lstnew((int)tmp);
		if (!new_node)
			return (1);
		ft_lstadd_back(stack, new_node);
		i++;
	}
	return (0);
}

static int	parse_and_init(t_node **stack_a, int ac, char **av)
{
	char	**args;

	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	if (!args || !*args || init_stack(stack_a, args) == 1)
	{
		if (ac == 2)
			free_split(args);
		return (1);
	}
	if (ac == 2)
		free_split(args);
	return (0);
}

static void	sort_stacks(t_node	**stack_a)
{
	t_node	*stack_b;
	int		size;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_4_5(stack_a, &stack_b);
	else
		radix_sort(stack_a, &stack_b);
	free_stack(&stack_b);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	if (parse_and_init(&stack_a, ac, av) == 1)
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		return (1);
	}
	if (!is_sorted(&stack_a))
	{
		index_stack(&stack_a);
		sort_stacks(&stack_a);
	}
	free_stack(&stack_a);
	return (0);
}
