/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:43:36 by bsalim            #+#    #+#             */
/*   Updated: 2025/06/24 17:29:04 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	newstr = ft_calloc((tals + 1), sizeof(char));
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
