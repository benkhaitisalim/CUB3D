/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:39:10 by taya              #+#    #+#             */
/*   Updated: 2025/11/01 16:39:13 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

void	opening_simulation(t_game *game, int i)
{
	if (game->doors[i].is_opening)
	{
		if (game->doors[i].open_progress < 1.0)
		{
			game->doors[i].open_progress += game->doors[i].animation_speed;
			if (game->doors[i].open_progress > 1.0)
				game->doors[i].open_progress = 1.0;
		}
	}
	else
	{
		if (game->doors[i].open_progress > 0.0)
		{
			game->doors[i].open_progress -= game->doors[i].animation_speed;
			if (game->doors[i].open_progress < 0.0)
				game->doors[i].open_progress = 0.0;
		}
	}
}

void	update_door(t_game *game)
{
	float	distance;
	int		i;

	i = 0;
	while (i < game->door_count)
	{
		distance = distance_calcul(game->player->pos_x, game->player->pos_y,
				game->doors[i].x + 0.5, game->doors[i].y + 0.5);
		if (distance < game->door_trigger_distance)
			game->doors[i].is_opening = 1;
		else
			game->doors[i].is_opening = 0;
		opening_simulation(game, i);
		i++;
	}
}

int	door_passable(t_game *game, int door_index)
{
	if (door_index < 0 || door_index >= game->door_count)
		return (0);
	return (game->doors[door_index].open_progress > 0.8);
}

int	is_valid_pos_with_doors(t_game *game, t_map *map, double x, double y)
{
	int		map_x;
	int		map_y;
	char	check;
	int		door_index;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= map->height || map_x < 0)
		return (0);
	if (map_x >= (int)ft_strlen(map->map_data[map_y]))
		return (0);
	check = map->map_data[map_y][map_x];
	if (check == '1')
		return (0);
	if (check == 'D')
	{
		door_index = is_door(game, map_x, map_y);
		if (door_index >= 0)
			return (door_passable(game, door_index));
	}
	return (1);
}
