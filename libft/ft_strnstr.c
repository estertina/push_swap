/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:52:51 by esttina           #+#    #+#             */
/*   Updated: 2025/08/26 05:48:01 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	if (needle[z] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i + z < len)
	{
		if (haystack[i + z] == needle[z])
			z++;
		else
		{
			i++;
			z = 0;
		}
		if (needle[z] == '\0')
			return ((char *)&haystack[i]);
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strnstr("findneedle", "needle", 10));
// 	printf("%s\n", ft_strnstr("findneedle", "needle", 2));
// 	printf("%s\n", ft_strnstr("findneedle", "", 10));
// 	printf("%s\n", ft_strnstr("findneedle", "hello", 10));

// 	return (0);
// }
