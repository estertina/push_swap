/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 03:59:35 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:17:09 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr1;
	const char	*ptr2;
	size_t		i;

	i = 0;
	ptr1 = (char *)dst;
	ptr2 = (const char *)src;
	if (n == 0)
		return (dst);
	if (n > 0 && ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {

// 	char dst[] = "hello";
// 	char src[] = "byee";

// 	printf("%s\n", ft_memcpy(dst, src, 5));
// 	return (0);
// }
