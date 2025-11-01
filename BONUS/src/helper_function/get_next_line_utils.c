/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:19:07 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/31 22:50:25 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length])
		++length;
	return (length);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*string;
	size_t	sizetotal;
	size_t	index;

	index = 0;
	sizetotal = size * count;
	string = malloc(sizetotal);
	if (!string)
		return (NULL);
	while (index < sizetotal)
	{
		string[index] = 0;
		index++;
	}
	return (string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tals;
	size_t	index;
	size_t	index2;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	tals = ft_strlen(s1) + ft_strlen(s2);
	index2 = 0;
	index = 0;
	newstr = malloc((tals + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[index])
	{
		newstr[index2++] = s1[index++];
	}
	index = 0;
	while (s2[index])
	{
		newstr[index2++] = s2[index++];
	}
	newstr[index2] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *string)
{
	char	*new;
	size_t	index;
	size_t	total;

	index = 0;
	total = ft_strlen(string);
	if (!string)
		return (NULL);
	new = malloc(ft_strlen(string) + 1);
	if (!new)
		return (NULL);
	while (index < total)
	{
		new[index] = string[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
