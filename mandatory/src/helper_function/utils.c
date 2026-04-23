/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:16:14 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/08 16:57:38 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	return (i);
}

int	ft_word(char *input)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (input[index])
	{
		while (input[index] && ft_isspace(input[index]))
			index++;
		if (input[index])
			count++;
		while (input[index] && !ft_isspace(input[index]))
			index++;
	}
	return (count);
}

void	*xrealloc(void *ptr, size_t new_count, size_t elem)
{
	void	*n;

	n = malloc(new_count * elem);
	if (!n)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(n, ptr, new_count * elem / 2);
		free(ptr);
	}
	return (n);
}

int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'K' || c == 'U');
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
