/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 06:35:48 by esttina           #+#    #+#             */
/*   Updated: 2025/08/21 03:51:14 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_sign(int i)
{
	if (i < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = ft_sign(n);
	count = ft_count(n);
	str = malloc(count + sign + 1);
	if (!str)
		return (NULL);
	str[count + sign] = '\0';
	if (sign == 1)
		n = -n;
	while (count != 0)
	{
		str[count + sign - 1] = (n % 10) + 48;
		n = n / 10;
		count--;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(123));
// 	printf("%s\n", ft_itoa(-123));
// 	return (0);
// }
