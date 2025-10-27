/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 04:25:43 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/14 02:33:09 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lentdst;
	size_t	lentsrc;

	lentdst = ft_strlen(dst);
	lentsrc = ft_strlen(src);
	if (lentdst > dstsize)
	{
		lentdst = dstsize;
	}
	if (lentdst == dstsize)
		return (dstsize + lentsrc);
	if (lentsrc < dstsize - lentdst)
		ft_memcpy(dst + lentdst, src, lentsrc + 1);
	else
	{
		ft_memcpy(dst + lentdst, src, dstsize - lentdst - 1);
		dst[dstsize - 1] = '\0';
	}
	return (lentdst + lentsrc);
}
