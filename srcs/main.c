/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:42:18 by esttina           #+#    #+#             */
/*   Updated: 2026/07/13 07:55:48 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	long	tmp;
	int		i;

	if (ac < 2)
		return (0);
	i = 1;
	while (i < ac)
	{
		tmp = ft_atol(av[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
}
