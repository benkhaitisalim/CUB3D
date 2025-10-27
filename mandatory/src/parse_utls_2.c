/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utls_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmat <swilmat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:20 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 14:59:36 by swilmat          ###   ########.fr       */
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

int	set_texture_if_match(t_map *map, char *line, int i)
{
	char	**target;

	target = NULL;
	if ((line[i] == 'N' || line[i] == 'n')
		&& (line[i + 1] == 'O' || line[i + 1] == 'o')
		&& ft_isspace(line[i + 2]))
	{
		target = &map->no_textures;
		map->count.no++;
	}
	else if ((line[i] == 'S' || line[i] == 's')
		&& (line[i + 1] == 'O' || line[i + 1] == 'o')
		&& ft_isspace(line[i + 2]))
	{
		target = &map->so_textures;
		map->count.so++;
	}
	else if ((line[i] == 'W' || line[i] == 'w')
		&& (line[i + 1] == 'E' || line[i + 1] == 'e')
		&& ft_isspace(line[i + 2]))
	{
		target = &map->we_textures;
		map->count.we++;
	}
	else if ((line[i] == 'E' || line[i] == 'e')
		&& (line[i + 1] == 'A' || line[i + 1] == 'a')
		&& ft_isspace(line[i + 2]))
	{
		target = &map->ea_textures;
		map->count.ea++;
	}
	if (target == NULL)
		return (-1);
	*target = ft_get_texture(line);
	if (*target == NULL)
		return (1);
	return (0);
}
