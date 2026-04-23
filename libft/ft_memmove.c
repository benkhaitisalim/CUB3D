/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 06:48:51 by bsalim            #+#    #+#             */
/*   Updated: 2025/06/24 17:27:02 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sorc;

	if (!src)
		return (NULL);
	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dest > sorc)
	{
		while (len-- > 0)
			dest[len] = sorc[len];
	}
	else
		ft_memcpy(dest, sorc, len);
	return (dest);
}
