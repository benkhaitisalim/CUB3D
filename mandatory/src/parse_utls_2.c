/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utls_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:20 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/31 22:14:22 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

char	*found_the_parse_value(char *line)
{
	int		s;
	char	*input;

	s = 0;
	input = NULL;
	while (*line)
	{
		while (*line && ft_isspace(*line))
			line++;
		if (*line)
		{
			s++;
			if (s == 2)
			{
				if (ft_isdigit(*line))
				{
					input = line;
				}
				else
					return (NULL);
			}
			line++;
		}
	}
	return (input);
}

int	check_diagonal(char *input)
{
	int	i;
	int	len;

	i = 0;
	while (input[i] && ft_isspace(input[i]))
		i++;
	len = ft_strlen(input);
	while (len > 0 && ft_isspace(input[len]))
		len--;
	if (input[i] != '1' && input[len] == '1')
		return (1);
	return (0);
}

int	remove_new_line(char *line)
{
	int	len;
	int	i;

	i = skip_space(line);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (i);
}

void	allocate_map(t_map *map, t_var1 variable, int *row, int *capacity)
{
	if (*row >= *capacity - 1)
	{
		variable.new_cap = (*capacity) * 2;
		variable.tmp = xrealloc(map->map_data,
				variable.new_cap, sizeof(char *));
		if (!variable.tmp)
			return ;
		map->map_data = variable.tmp;
		*capacity = variable.new_cap;
	}
}
