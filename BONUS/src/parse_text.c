/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:29:19 by taya              #+#    #+#             */
/*   Updated: 2025/11/08 21:33:42 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

int	match_texture_type(char *line, int i, t_map *map, char ***target)
{
	if ((line[i] == 'N' || line[i] == 'n') && (line[i + 1] == 'O' || line[i
				+ 1] == 'o') && ft_isspace(line[i + 2]))
	{
		map->count.no++;
		return (*target = &map->no_textures, 1);
	}
	else if ((line[i] == 'S' || line[i] == 's') && (line[i + 1] == 'O' || line[i
				+ 1] == 'o') && ft_isspace(line[i + 2]))
	{
		map->count.so++;
		return (*target = &map->so_textures, 1);
	}
	else if ((line[i] == 'W' || line[i] == 'w') && (line[i + 1] == 'E' || line[i
				+ 1] == 'e') && ft_isspace(line[i + 2]))
	{
		map->count.we++;
		return (*target = &map->we_textures, 1);
	}
	else if ((line[i] == 'E' || line[i] == 'e') && (line[i + 1] == 'A' || line[i
				+ 1] == 'a') && ft_isspace(line[i + 2]))
	{
		map->count.ea++;
		return (*target = &map->ea_textures, 1);
	}
	return (0);
}

int	set_texture_if_match(t_map *map, char *line, int i)
{
	char	**target;

	target = NULL;
	if (!match_texture_type(line, i, map, &target))
		return (1);
	if (map->count.so > 1 || map->count.ea > 1 
		|| map->count.no > 1 || map->count.we > 1)
		return (1);
	*target = ft_get_texture(line);
	if (*target == NULL)
		return (1);
	return (0);
}
