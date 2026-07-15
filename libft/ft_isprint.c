/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:53:47 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:16:27 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isprint(31));
// 	printf("%d\n", ft_isprint(100));
// 	printf("%d\n", ft_isprint(127));
// }
