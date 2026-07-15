/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:43:45 by esttina           #+#    #+#             */
/*   Updated: 2025/08/08 21:50:26 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// int	main(void)
// {
// 	char	*mem = ft_calloc(5, 5);

// 	printf("First byte: %d\n", mem[0]);
// 	printf("Second byte: %d\n", mem[1]);
// 	printf("Third byte: %d\n", mem[2]);
// 	printf("Fourth byte: %d\n", mem[3]);

// 	free(mem);
// 	return (0);
// }
