/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:35:00 by esttina           #+#    #+#             */
/*   Updated: 2026/05/23 12:56:43 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join(char *line, char *remainder, char *tmp)
{
    int	i;
    int	c;
    
    i = 0;
    c = 0;
    while (line && line[i])
    {
        tmp[i] = line[i];
        i++;
    }
    while (remainder[c])
    {
        tmp[i++] = remainder[c];
        if (remainder[c] == '\n')
        {
            c++;
            break ;
        }
        c++;
    }
    tmp[i] = '\0';
    i = 0;
    while (remainder[c])
    remainder[i++] = remainder[c++];
    remainder[i] = '\0';
}

static char	*join_alloc(char *line, char *remainder)
{
    char	*tmp;
    int		line_len;
    int		rem_len;
    
    line_len = 0;
    rem_len = 0;
    if (line)
    line_len = ft_strlen(line);
    while (remainder[rem_len] && remainder[rem_len] != '\n')
    rem_len++;
    if (remainder[rem_len] == '\n')
    rem_len++;
    tmp = malloc(line_len + rem_len + 1);
    if (!tmp)
    return (free(line), NULL);
    join(line, remainder, tmp);
    free(line);
    return (tmp);
}

static char	*read_and_join(int fd, char *remainder)
{
    char	*line;
	int		bytes_read;
    
	line = NULL;
	if (ft_strchr(remainder, '\n'))
    return (join_alloc(line, remainder));
	if (remainder[0] != '\0')
	{
        line = join_alloc(line, remainder);
		if (!line)
        return (NULL);
	}
	while (!line || !ft_strchr(line, '\n'))
	{
        bytes_read = read(fd, remainder, BUFFER_SIZE);
		if (bytes_read < 0)
        return (remainder[0] = '\0', free(line), NULL);
		if (bytes_read == 0)
        break ;
		remainder[bytes_read] = '\0';
		line = join_alloc(line, remainder);
		if (!line)
        return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
    static char	remainder[MAX_FD][BUFFER_SIZE + 1];
    char		*line;

    if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
        return (NULL);
    line = read_and_join(fd, remainder[fd]);
    if (!line)
        remainder[fd][0] = '\0';
    return (line);
}

// int	main(void)
// {
    // 	int		fd1, fd2, fd3;
    // 	char	*line
    // 	printf("\nROUND 1\n");
    
// 	line = get_next_line(fd1);
// 		printf("FD %d: %s", fd1, line);
// 	free(line);

// 	line = get_next_line(fd2);
// 	if (line)
// 		printf("FD %d: %s", fd2, line);
// 	free(line);

// 	line = get_next_line(fd3);
// 	if (line)
// 		printf("FD %d: %s", fd3, line);
// 	free(line);

// 	printf("\nROUND 2\n");

// 	line = get_next_line(fd1);
// 	if (line)
// 		printf("FD %d: %s", fd1, line);
// 	free(line);

// 	line = get_next_line(fd2);
// 	if (line)
// 		printf("FD %d: %s", fd2, line);
// 	free(line);

// 	line = get_next_line(fd3);
// 	if (line)
// 		printf("FD %d: %s", fd3, line);
// 	free(line);

// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }