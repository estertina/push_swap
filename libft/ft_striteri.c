/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 08:38:40 by esttina           #+#    #+#             */
/*   Updated: 2025/08/21 09:06:49 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// static void	uppercase(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 97 && *c <= 122)
// 		*c -= 32;
// }

// int	main(void)
// {
// 	char	str[] = "hello";

// 	ft_striteri(str, uppercase);

// 	printf("%s\n", str);

// 	return (0);
// }