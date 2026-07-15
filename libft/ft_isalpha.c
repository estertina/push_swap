/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:36:07 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:16:10 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isalpha(65));
// 	printf("%d\n", ft_isalpha('A'));
// 	printf("%d\n", ft_isalpha('7'));
// 	return (0);
// }
