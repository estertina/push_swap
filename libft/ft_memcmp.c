/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:29:05 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:17:04 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	unsigned char		*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_memcmp("Iamstring", "Metoo", 4));
// 	printf("%d\n", ft_memcmp("Iamstring", "Iamalsostring", 4));
// 	return (0);
// }
