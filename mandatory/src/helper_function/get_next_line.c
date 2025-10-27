/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:16:07 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 00:16:08 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <time.h>

char	*get_line_from_buffer(int fd, char *left_c, char *buffer);
char	*set_line(char *line_buffer);
char	*ft_strrchr(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	if ((fd < 0 || BUFFER_SIZE <= 0) || read(fd, 0, 0) < 0)
	{
		free(left_c);
		left_c = NULL;
		return (NULL);
	}
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	line = get_line_from_buffer(fd, left_c, buffer);
	left_c = set_line(line);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	charachter;

	if (!s)
		return (NULL);
	str = (char *)s;
	charachter = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == charachter)
		{
			return (&str[i]);
		}
		i++;
	}
	if (charachter == '\0')
		return (&str[i]);
	return (NULL);
}

char	*get_line_from_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*temporary;

	b_read = 1;
	if (!buffer)
		return (NULL);
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (left_c);
		else if (b_read == 0 && !left_c)
			break ;
		buffer[b_read] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		temporary = left_c;
		left_c = ft_strjoin(temporary, buffer);
		free(temporary);
		temporary = NULL;
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

char	*set_line(char *line_buffer)
{
	char	*left_c;
	int		index;

	index = 0;
	if (line_buffer)
	{
		while (line_buffer[index] != '\n' && line_buffer[index] != '\0')
			index++;
		if (line_buffer[index] == '\0')
			return (NULL);
		left_c = ft_strdup((line_buffer) + (index + 1));
		if (!left_c)
			return (NULL);
		if (*left_c == '\0')
		{
			free(left_c);
			left_c = NULL;
		}
		line_buffer[index + 1] = '\0';
		return (left_c);
	}
	return (NULL);
}
