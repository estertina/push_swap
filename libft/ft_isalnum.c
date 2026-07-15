/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:21:47 by esttina           #+#    #+#             */
/*   Updated: 2025/08/07 21:16:02 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isalnum(90));
// 	printf("%d\n", ft_isalnum(95));
// 	printf("%d\n", ft_isalnum(50));
// }
