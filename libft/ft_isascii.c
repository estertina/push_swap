/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:37:04 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:16:15 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isascii(-1));
// 	printf("%d\n", ft_isascii(60));
// 	printf("%d\n", ft_isascii(128));
// }
