/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:04:25 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:17:56 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		else if (str1[i] == '\0' && str2[i] == '\0')
			return (0);
		else
			i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_strncmp("helo", "help", 8));
// 	return (0);
// }
