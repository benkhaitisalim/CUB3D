/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:29:19 by taya              #+#    #+#             */
/*   Updated: 2025/10/31 22:52:17 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

int	match_texture_type(char *line, int i, t_map *map, char ***target)
{
	if ((line[i] == 'N' || line[i] == 'n') && (line[i + 1] == 'O' || line[i
				+ 1] == 'o') && ft_isspace(line[i + 2]))
		return (*target = &map->no_textures, map->count.no++, 1);
	else if ((line[i] == 'S' || line[i] == 's') && (line[i + 1] == 'O' || line[i
				+ 1] == 'o') && ft_isspace(line[i + 2]))
		return (*target = &map->so_textures, map->count.so++, 1);
	else if ((line[i] == 'W' || line[i] == 'w') && (line[i + 1] == 'E' || line[i
				+ 1] == 'e') && ft_isspace(line[i + 2]))
		return (*target = &map->we_textures, map->count.we++, 1);
	else if ((line[i] == 'E' || line[i] == 'e') && (line[i + 1] == 'A' || line[i
				+ 1] == 'a') && ft_isspace(line[i + 2]))
		return (*target = &map->ea_textures, map->count.ea++, 1);
	return (0);
}

int	set_texture_if_match(t_map *map, char *line, int i)
{
	char	**target;

	target = NULL;
	if (!match_texture_type(line, i, map, &target))
		return (-1);
	*target = ft_get_texture(line);
	if (*target == NULL)
		return (1);
	return (0);
}
