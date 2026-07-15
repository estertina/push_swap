/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:15:11 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:16:58 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str;

	i = 0;
	ch = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s\n", ft_memchr("what's up", ' ', 5));
// 	printf("%s\n", ft_memchr("what's up", 'a', 5));
// 	return (0);
// }
