/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 04:08:08 by esttina           #+#    #+#             */
/*   Updated: 2025/08/21 05:59:18 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// static char	uppercase(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 97 && c <= 122)
// 		c -= 32;
// 	return (c);
// }

// int	main(void)
// {
// 	char	*str;
// 	char	*upper;

// 	str = "hello";
// 	upper = ft_strmapi(str, uppercase);

// 	printf("%s\n", upper);

// 	free(upper);
// 	return (0);
// }
