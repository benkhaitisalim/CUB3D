/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:11 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/31 22:33:21 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

char	*derive_base_dir(const char *av)
{
	char	*pos;
	size_t	len;
	char	*base;

	if (!av)
		return (ft_strdup("."));
	pos = ft_strnstr(av, "/maps/", ft_strlen(av));
	if (pos)
	{
		len = (size_t)(pos - av);
		return (ft_substr(av, 0, len));
	}
	len = ft_strlen(av);
	while (len > 0 && av[len - 1] != '/')
		len--;
	if (len == 0)
		return (ft_strdup("."));
	base = ft_substr(av, 0, len - 1);
	if (!base || base[0] == '\0')
	{
		if (base)
			free(base);
		return (ft_strdup("."));
	}
	return (base);
}

static int	finalize_map(t_map *map, int row)
{
	map->map_data[row] = NULL;
	map->height = row;
	return (0);
}

int	handle_parse_error(t_map *map, int row)
{
	if (row > 0)
	{
		while (--row >= 0)
			free(map->map_data[row]);
	}
	free(map->map_data);
	map->map_data = NULL;
	if (map->no_textures)
		free(map->no_textures);
	if (map->so_textures)
		free(map->so_textures);
	if (map->we_textures)
		free(map->we_textures);
	if (map->ea_textures)
		free(map->ea_textures);
	return (1);
}

int	parse_map(t_map *map, int fd)
{
	int	capacity;
	int	row;

	capacity = 32;
	row = 0;
	map->map_data = malloc(sizeof(char *) * capacity);
	if (!map->map_data)
		return (1);
	if (process_file_lines(map, fd, &capacity, &row) != 0)
		return (handle_parse_error(map, row));
	return (finalize_map(map, row));
}

int	process_file_lines(t_map *map, int fd, int *capacity, int *row)
{
	t_var	variable;

	variable.before_map = 1;
	while (1)
	{
		variable.line = get_next_line(fd);
		if (variable.line == NULL)
			break ;
		variable.i = remove_new_line(variable.line);
		if (variable.line[0] == '\0')
		{
			free(variable.line);
			if (variable.before_map)
				continue ;
			if (drain_after_map(fd) != 0)
				return (1);
			break ;
		}
		if (parse_split(map, capacity, row, &variable) != 0)
			return (1);
		free(variable.line);
	}
	return (0);
}
