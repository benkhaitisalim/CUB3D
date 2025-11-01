/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:47:42 by taya              #+#    #+#             */
/*   Updated: 2025/10/31 22:43:28 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validate_textures(t_map *map, t_var_check *var)
{
	if (!map->no_textures || !map->so_textures || !map->we_textures
		|| !map->ea_textures)
	{
		printf("texture not found\n");
		return (1);
	}
	var->count_textur = map->count.no + map->count.so + map->count.ea
		+ map->count.we;
	if (map->count.no > 1 || map->count.so > 1 || map->count.ea > 1
		|| map->count.we > 1)
	{
		printf("texture daplicated \n");
		return (1);
	}
	if (var->count_textur > 4 || map->count_color > 2)
	{
		printf("number off texture or color not ok\n");
		return (1);
	}
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
		j = 0;
		while (var.row[j])
		{
			if (!is_map_char(var.row[j]) && !ft_isspace(var.row[j]))
			{
				printf("this is not map char '%c'\n", var.row[j]);
				free(var.row);
				return (1);
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
	int			pos[2];

	if (validate_textures(map, &var) != 0)
		return (1);
	if (copy_double_arr(map, &var) != 0)
		return (1);
	pos[0] = 0;
	pos[1] = 0;
	if (find_player_position1(var.copy, pos, map->height) != 0)
		return (1);
	if (ft_check_start_map(&var) != 1 || ft_check_end_map(&var, map) != 1)
		return (1);
	if (validate_map_chars(map) != 0)
	{
		free_double_arr(var.copy);
		return (1);
	}
	free_double_arr(var.copy);
	return (0);
}
