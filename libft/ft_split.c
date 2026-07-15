/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 06:36:29 by esttina           #+#    #+#             */
/*   Updated: 2025/08/28 00:18:57 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_arr(char **word_arr, int filled)
{
	int	i;

	i = 0;
	while (i < filled)
	{
		free(word_arr[i]);
		i++;
	}
	free(word_arr);
}

static char	**word_cpy(char **word_arr, char const *str, char del, int w_count)
{
	int				i;
	int				j;
	unsigned int	word_start;

	i = 0;
	j = 0;
	while (str[i] && j < w_count)
	{
		if (str[i] == del)
			i++;
		else if (str[i] != del)
		{
			word_start = i;
			while (str[i] != del && str[i] != '\0')
				i++;
			word_arr[j] = ft_substr(str, word_start, i - word_start);
			if (!word_arr[j])
				return (free_arr(word_arr, j), NULL);
			j++;
		}
	}
	word_arr[w_count] = NULL;
	return (word_arr);
}

static int	word_count(char const *s, char c)
{
	int		i;
	int		word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			word_count++;
		}
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**word_arr;
	int		w_count;

	if (!s)
		return (NULL);
	w_count = word_count(s, c);
	word_arr = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!word_arr)
		return (NULL);
	word_arr[w_count] = NULL;
	if (!word_cpy(word_arr, s, c, w_count))
		return (NULL);
	return (word_arr);
}

// int main(void)
// {
// 	char const *s = "Hello my name is Ester";
// 	char	c = ' ';
// 	char	**arrrrr = ft_split(s, c);
// 	int i = 0;

// 	while (arrrrr[i])
// 	{
// 		printf("%s\n", arrrrr[i]);
// 		i++;
// 	}
// 	return (0);
// }
