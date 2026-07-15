/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:22:05 by esttina           #+#    #+#             */
/*   Updated: 2025/08/10 21:56:50 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr1;
	const char	*ptr2;
	size_t		i;

	i = 0;
	ptr1 = (char *)dst;
	ptr2 = (const char *)src;
	if (len == 0)
		return (dst);
	if (len > 0 && ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	while (i < len)
	{
		if (ptr1 < ptr2)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
		else
		{
			ptr1[len - 1] = ptr2[len - 1];
			len--;
		}
	}
	return (dst);
}

// int	main(void)
// {

// 	char dst[] = "helloooooooooo";
// 	char src[] = "byeeeeeeee";

// 	printf("%s\n", (char *)ft_memmove(dst, src, 10));
// 	return (0);
// }