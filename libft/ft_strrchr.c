/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 08:32:55 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:18:02 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*str;
	char	*last;

	i = 0;
	ch = (char)c;
	str = (char *)s;
	last = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			last = (&str[i]);
		i++;
	}
	if (ch == '\0')
		return (&str[i]);
	return (last);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strrchr("hello", 'f'));
// 	printf("%s\n", ft_strrchr("hello", 'l'));
// 	printf("%s\n", ft_strrchr("hello", '\0'));
// 	return (0);
// }
