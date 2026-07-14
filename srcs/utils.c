/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:42:15 by esttina           #+#    #+#             */
/*   Updated: 2026/07/14 09:09:34 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_validity(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;

	if (str[i] == '\0')
		return (1);
	
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (1);
			i++;
		}
		return (0);
}

int	check_duplicates(t_node *stack, int n)
{
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
