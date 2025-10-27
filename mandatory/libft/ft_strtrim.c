/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:10:19 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/14 02:26:50 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftcheking(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strnew;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !*s1)
		return (ft_strdup(""));
	if (!set)
		return ((char *)s1);
	while (ftcheking(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (ftcheking(set, s1[end]))
		end--;
	strnew = ft_substr(s1, start, end - start + 1);
	return (strnew);
}
