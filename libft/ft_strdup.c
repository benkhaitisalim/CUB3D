/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:42:53 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/14 02:24:48 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*savestring;
	size_t	s;

	s = ft_strlen(s1);
	savestring = malloc(s + 1);
	if (!savestring)
	{
		return (NULL);
	}
	ft_memcpy(savestring, s1, ft_strlen(s1) + 1);
	return (savestring);
}
