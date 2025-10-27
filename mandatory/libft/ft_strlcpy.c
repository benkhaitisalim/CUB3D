/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:19:34 by bsalim            #+#    #+#             */
/*   Updated: 2025/08/21 11:26:23 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lentsrc;

	lentsrc = ft_strlen(src);
	if (dstsize == 0)
	{
		return (lentsrc);
	}
	if (lentsrc > dstsize - 1)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	else
		ft_memcpy(dst, src, lentsrc + 1);
	return (lentsrc);
}
