/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:04:29 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/13 23:03:19 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	anything;
	size_t			i;

	string = (unsigned char *)s;
	anything = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (string[i] == anything)
		{
			return (&string[i]);
		}
		i++;
	}
	return (NULL);
}
