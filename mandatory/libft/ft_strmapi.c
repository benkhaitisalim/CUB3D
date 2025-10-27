/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:34:15 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/14 02:34:39 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	size_t			lenths1;
	unsigned int	index;

	index = 0;
	lenths1 = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	newstr = malloc((lenths1 + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (index < lenths1)
	{
		newstr[index] = (*f)(index, s[index]);
		index++;
	}
	newstr[index] = '\0';
	return (newstr);
}
