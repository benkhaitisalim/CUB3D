/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:01:11 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/14 04:28:28 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_lenth(long nbr, ssize_t count)
{
	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static char	*newstring(ssize_t len)
{
	char	*stringnew;

	stringnew = malloc(len + 1);
	return (stringnew);
}

char	*ft_itoa(int n)
{
	ssize_t	len;
	ssize_t	i;
	char	*result;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = int_lenth(n, 0);
	result = newstring(len);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		result[i++] = '-';
	}
	result[len] = '\0';
	while (len > i)
	{
		result[--len] = ((n % 10) + 48);
		n = n / 10;
	}
	return (result);
}
