/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 07:08:59 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/21 02:15:52 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	kalimat(char const *s, char c)

{
	int i;
	int ch7al;

	i = 0;
	ch7al = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			ch7al++;
		}
		i++;
	}
	return (ch7al);
}

char	**ft_split(char const *s, char c)

{
	int i;
	int fin;
	int debut;
	char **new;
	int j;

	j = 0;
	i = -1;
	if (!s)
		return (0);
	new = (char **)malloc((kalimat(s, c) + 1) * sizeof(char *));
	if (!new)
		return (0);
	while (s[++i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			debut = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			fin = i;
			new[j++] = ft_substr(s, debut, fin - debut + 1);
		}
	}
	new[j] = NULL;
	return (new);
}
