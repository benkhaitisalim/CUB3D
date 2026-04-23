/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:32:40 by taya              #+#    #+#             */
/*   Updated: 2025/11/01 16:21:52 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_player_position(char **map, double *pos_x, double *pos_y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				*pos_x = j + 0.5;
				*pos_y = i + 0.5;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	find_player_direction(char **map, double *dir_x, double *dir_y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return (*dir_x = 0, *dir_y = -1, 1);
			else if (map[i][j] == 'S')
				return (*dir_x = 0, *dir_y = 1, 1);
			else if (map[i][j] == 'E')
				return (*dir_x = 1, *dir_y = 0, 1);
			else if (map[i][j] == 'W')
				return (*dir_x = -1, *dir_y = 0, 1);
			j++;
		}
		i++;
	}
	return (0);
}

void	set_camera_plane(double dir_x, double dir_y, double *plane_x,
		double *plane_y)
{
	if (dir_x == 0 && dir_y == -1)
	{
		*plane_x = 0.66;
		*plane_y = 0;
	}
	else if (dir_x == 0 && dir_y == 1)
	{
		*plane_x = -0.66;
		*plane_y = 0;
	}
	else if (dir_x == 1 && dir_y == 0)
	{
		*plane_x = 0;
		*plane_y = 0.66;
	}
	else if (dir_x == -1 && dir_y == 0)
	{
		*plane_x = 0;
		*plane_y = -0.66;
	}
}

int	is_valid_position(t_map *map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= map->height || map_x < 0)
		return (0);
	if (map_x >= (int)ft_strlen(map->map_data[map_y]))
		return (0);
	return (map->map_data[map_y][map_x] != '1');
}

int	init_player(t_player *player, t_map *map, t_mlx_data *data)
{
	init_player_var(player);
	if (!find_player_position(map->map_data, &player->pos_x, &player->pos_y))
		return (1);
	if (!find_player_direction(map->map_data, &player->dir_x, &player->dir_y))
		return (2);
	set_camera_plane(player->dir_x, player->dir_y,
		&player->plane_x, &player->plane_y);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Cube3D - Treasure Hunt");
	if (!data->win)
		return (1);
	return (0);
}
