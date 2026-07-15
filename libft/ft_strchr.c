/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:53:45 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:17:27 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*str;

	i = 0;
	ch = (char)c;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	if (ch == '\0')
		return (&str[i]);
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strchr("hello", 'f'));
// 	printf("%s\n", ft_strchr("hello", 'e'));
// 	printf("%s\n", ft_strchr("hello", '\0'));
// 	return (0);
// }
