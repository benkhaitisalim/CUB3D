/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:47:42 by taya              #+#    #+#             */
/*   Updated: 2025/11/08 17:16:41 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validate_textures(t_map *map, t_var_check *var)
{
	if (!map->no_textures || !map->so_textures || !map->we_textures
		|| !map->ea_textures)
		return (error_msg("Error: missing texture"), 1);
	var->count_textur = map->count.no + map->count.so + map->count.ea
		+ map->count.we;
	if (map->count.no > 1 || map->count.so > 1 || map->count.ea > 1
		|| map->count.we > 1)
		return (error_msg("Error: duplicated texture"), 1);
	if (var->count_textur > MAX_TEXTURES || map->count_color > MAX_COLORS)
		return (error_msg("Error: too many colors"), 1);
	return (0);
}

int	validate_map_chars(t_map *map)
{
	t_var_check	var;
	int			i;
	int			j;

	i = 0;
	var.player_count = 0;
	while (i < map->height)
	{
		var.row = ft_strdup(map->map_data[i]);
		if (!var.row)
			return (error_msg("Error: memory allocation failed"), 1);
		j = 0;
		while (var.row[j])
		{
			if (!is_map_char(var.row[j]) && !ft_isspace(var.row[j]))
			{
				free(var.row);
				return (error_msg("Error: invalid map character"), 1);
			}
			j++;
		}
		free(var.row);
		i++;
	}
	return (0);
}

int	validate_map(t_map *map)
{
	t_var_check	var;

	if (validate_textures(map, &var) != 0)
		return (1);
	if (copy_double_arr(map, &var) != 0)
		return (1);
	var.pos[0] = 0;
	var.pos[1] = 0;
	if (find_player_position1(var.copy, var.pos, map->height) != 0)
	{
		free_double_arr(var.copy);
		return (1);
	}
	if (ft_check_start_map(&var) != 1 || ft_check_end_map(&var, map) != 1)
	{
		free_double_arr(var.copy);
		return (1);
	}
	if (validate_map_chars(map) != 0)
	{
		free_double_arr(var.copy);
		return (1);
	}
	free_double_arr(var.copy);
	return (0);
}
