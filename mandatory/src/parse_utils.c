/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:15 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/08 16:57:28 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

int	set_color_if_match(t_map *map, char *line, int i)
{
	if (ft_strncmp(line + i, "f ", 2) == 0 || ft_strncmp(line + i, "F ", 2) == 0
		|| ft_strnstr(line + i, "Floor ", 7) != NULL)
	{
		map->count_color++;
		return (find_color_and_parse_them(map, line, 'F'));
	}
	if (ft_strncmp(line + i, "c ", 2) == 0 || ft_strncmp(line + i, "C ", 2) == 0
		|| ft_strnstr(line + i, "Ceilling ", 7) != NULL)
	{
		map->count_color++;
		return (find_color_and_parse_them(map, line, 'C'));
	}
	return (-1);
}

int	drain_after_map(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\n')
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

int	process_map(t_map *map, char *line, int *capacity, int *row)
{
	t_var1	var;

	var.valid = 1;
	var.ci = 0;
	var.skip = skip_space(line);
	while (line[var.ci + var.skip])
	{
		if (!is_map_char(line[var.ci + var.skip]) && !ft_isspace(line[var.ci
					+ var.skip]))
		{
			var.valid = 0;
			break ;
		}
		var.ci++;
	}
	if (!var.valid)
		return (1);
	allocate_map(map, var, row, capacity);
	map->map_data[*row] = ft_strdup(line);
	if (!map->map_data[*row])
		return (1);
	if ((int)ft_strlen(line) > map->width)
		map->width = ft_strlen(line);
	(*row)++;
	return (0);
}

static int	handle_header_line(t_map *map, char *line, int i, int *before_map)
{
	if (set_texture_if_match(map, line, i) == 0)
		return (0);
	if (set_color_if_match(map, line, i) == 0)
		return (0);
	if (!check_diagonal(line))
	{
		*before_map = 0;
		return (0);
	}
	return (1);
}

int	parse_split(t_map *map, int *capacity, int *row, t_var *variable)
{
	int	s;

	s = 0;
	if (variable->before_map)
	{
		if (handle_header_line(map, variable->line, variable->i,
				&variable->before_map) != 0)
		{
			free(variable->line);
			return (1);
		}
		if (!variable->before_map)
		{
			s = skip_space(variable->line);
			if (variable->line[s] != '\0')
			{
				if (process_map(map, variable->line, capacity, row) != 0)
					return (free(variable->line), 1);
			}
		}
	}
	else if (process_map(map, variable->line, capacity, row) != 0)
		return (free(variable->line), 1);
	return (0);
}
