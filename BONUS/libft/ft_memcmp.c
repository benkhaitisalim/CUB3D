/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:16:41 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/14 03:43:50 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	index = 0;
	str2 = (unsigned char *)s2;
	str1 = (unsigned char *)s1;
	if (n == 0)
		return (0);
	while (index < n)
	{
		if (str1[index] != str2[index])
		{
			return (str1[index] - str2[index]);
		}
		index++;
	}
	return (0);
}
