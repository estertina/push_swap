/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 07:25:01 by esttina           #+#    #+#             */
/*   Updated: 2025/08/15 07:49:51 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*newstr;

	c = 0;
	i = 0;
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		newstr[i + c] = s2[c];
		c++;
	}
	newstr[c + i] = '\0';
	return (newstr);
}

// int	main(void)
// {
// 	char const *s1 = "Iam";
// 	char const *s2 = "String";

// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
