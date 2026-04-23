/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:04:41 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/14 04:29:21 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*string;
	size_t	sizetotal;

	sizetotal = size * count;
	string = malloc(sizetotal);
	if (!string)
	{
		return (NULL);
	}
	ft_bzero(string, sizetotal);
	return (string);
}
