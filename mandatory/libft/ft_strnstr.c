/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 06:32:30 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/14 02:26:59 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hstack;
	char	*need;
	size_t	j;
	size_t	i;

	hstack = (char *)haystack;
	need = (char *)needle;
	i = 0;
	if (*need == '\0')
		return (hstack);
	while (i < len && hstack[i])
	{
		if (hstack[i] == need[0])
		{
			j = 0;
			while (hstack[i + j] == need[j] && i + j < len && need[j])
				j++;
			if (need[j] == '\0')
				return (&hstack[i]);
		}
		i++;
	}
	return (NULL);
}
