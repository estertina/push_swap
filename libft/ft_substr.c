/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:59:44 by esttina           #+#    #+#             */
/*   Updated: 2025/08/13 07:20:29 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	length_s;

	i = 0;
	length_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > length_s)
		return (ft_strdup("\0"));
	if (len > length_s - start)
		len = length_s - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
// int	main(void)
// {
// 	printf("%s\n", ft_substr("hello", 0, 10));
// 	printf("%s\n", ft_substr("hello", 5, 10));
// 	printf("%s\n", ft_substr("hello", 2, 2));
// 	printf("%s\n", ft_substr("", 2, 2));
// 	return (0);
// }
