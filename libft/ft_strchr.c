/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:31:41 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/20 02:11:28 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	charachter;

	str = (char *)s;
	charachter = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == charachter)
		{
			return (&str[i]);
		}
		i++;
	}
	if (charachter == '\0')
		return (&str[i]);
	return (NULL);
}
