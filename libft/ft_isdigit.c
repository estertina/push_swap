/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:30:43 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:16:22 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isdigit(65));
// 	printf("%d\n", ft_isdigit(49));
// 	printf("%d\n", ft_isdigit(58));
// 	return (0);
// }