/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:32:39 by taya              #+#    #+#             */
/*   Updated: 2025/11/01 16:32:55 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

float	distance_calcul(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int	is_door(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	if (!game->doors)
		return (-1);
	while (i < game->door_count)
	{
		if (game->doors[i].x == x && game->doors[i].y == y)
			return (i);
		i++;
	}
	return (-1);
}

int	count_doors(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->map_data[i])
	{
		j = 0;
		while (map->map_data[i][j])
		{
			if (map->map_data[i][j] == 'D')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	init_doors(t_game *game, t_map *map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map->map_data[i])
	{
		j = 0;
		while (map->map_data[i][j])
		{
			if (map->map_data[i][j] == 'D')
			{
				game->doors[count].x = j;
				game->doors[count].y = i;
				game->doors[count].is_opening = 0;
				game->doors[count].open_progress = 0.0;
				game->doors[count].animation_speed = 0.03;
				count++;
			}
			j++;
		}
		i++;
	}
	game->door_trigger_distance = 2.5;
}

void	parsing_doors(t_game *game, t_map *map)
{
	int	count;

	count = count_doors(map);
	game->door_count = count;
	if (count == 0)
	{
		game->doors = NULL;
		return ;
	}
	game->doors = malloc(sizeof(t_door) * count);
	if (!game->doors)
		return ;
	init_doors(game, map);
}
