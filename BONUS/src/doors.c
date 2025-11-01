/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:07:11 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/31 23:07:14 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

float	distance_calcul(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	parsing_doors(t_game *game, t_map *map)
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
	game->door_count = count;
	if (count == 0)
	{
		game->doors = NULL;
		return ;
	}
	game->doors = malloc(sizeof(t_door) * count);
	if (!game->doors)
		return ;
	count = 0;
	i = 0;
	j = 0;
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
		//hadchi b ytopena b speed
		if (game->doors[i].is_opening)
		{
			if (game->doors[i].open_progress < 1.0)
			{
				game->doors[i].open_progress += game->doors[i].animation_speed;
				if (game->doors[i].open_progress > 1.0)
					game->doors[i].open_progress = 1.0;
			}
		}
		// hadchi bach ytclosa b speed
		else
		{
			if (game->doors[i].open_progress > 0.0)
			{
				game->doors[i].open_progress -= game->doors[i].animation_speed;
				if (game->doors[i].open_progress < 0.0)
					game->doors[i].open_progress = 0.0;
			}
		}
		i++;
	}
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

int	door_passable(t_game *game, int door_index)
{
	if (door_index < 0 || door_index >= game->door_count)
		return (0);
	//okey hna dert door ykon mftoh wahd 80% then player pass
	return (game->doors[door_index].open_progress > 0.8);
}

void	dda_algo(t_game *game, t_ray *ray)
{
	int		index_door;
	char	check;
	int		hit_chance;

	while (ray->hit == 0)
	{
		// Move steps
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y >= 0 && ray->map_y < game->map->height && ray->map_x >= 0
			&& ray->map_x < (int)strlen(game->map->map_data[ray->map_y]))
		{
			check = game->map->map_data[ray->map_y][ray->map_x];
			if (check == '1')
				ray->hit = 1;
			else if (check == 'D')
			{
				index_door = is_door(game, ray->map_x, ray->map_y);
				if (index_door >= 0)
				{
					if (game->doors[index_door].open_progress < 0.2)
						ray->hit = 1;
					else if (game->doors[index_door].open_progress < 0.8)
					{
						hit_chance = (int)((1.0
									- game->doors[index_door].open_progress)
								* 100);
						if ((rand() % 100) < hit_chance)
							ray->hit = 1;
					}
				}
				else
					ray->hit = 1;
			}
		}
		else
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player->pos_x + (1
					- ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player->pos_y + (1
					- ray->step_y) / 2) / ray->dir_y;
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

void	move_player_fb(t_game *game, int direction)
{
	double	new_x;
	double	new_y;
	double	buffer_x;
	double	buffer_y;

	if (direction == 1)
	{
		new_x = game->player->pos_x + game->player->dir_x * MOVE_SPEED;
		new_y = game->player->pos_y + game->player->dir_y * MOVE_SPEED;
	}
	else
	{
		new_x = game->player->pos_x - game->player->dir_x * MOVE_SPEED;
		new_y = game->player->pos_y - game->player->dir_y * MOVE_SPEED;
	}
	if (new_x > game->player->pos_x)
		buffer_x = new_x + COLLISION_BUFFER;
	else
		buffer_x = new_x - COLLISION_BUFFER;
	if (new_y > game->player->pos_y)
		buffer_y = new_y + COLLISION_BUFFER;
	else
		buffer_y = new_y - COLLISION_BUFFER;
	if (is_valid_position(game->map, buffer_x, game->player->pos_y))
		game->player->pos_x = new_x;
	if (is_valid_position(game->map, game->player->pos_x, buffer_y))
		game->player->pos_y = new_y;
}

void	move_player_lf(t_game *game, int direction)
{
	double	new_x;
	double	new_y;
	double	buffer_x;
	double	buffer_y;

	if (direction == 1)
	{
		new_x = game->player->pos_x - game->player->plane_x * MOVE_SPEED;
		new_y = game->player->pos_y - game->player->plane_y * MOVE_SPEED;
	}
	else
	{
		new_x = game->player->pos_x + game->player->plane_x * MOVE_SPEED;
		new_y = game->player->pos_y + game->player->plane_y * MOVE_SPEED;
	}
	if (new_x > game->player->pos_x)
		buffer_x = new_x + COLLISION_BUFFER;
	else
		buffer_x = new_x - COLLISION_BUFFER;
	if (new_y > game->player->pos_y)
		buffer_y = new_y + COLLISION_BUFFER;
	else
		buffer_y = new_y - COLLISION_BUFFER;
	if (is_valid_position(game->map, buffer_x, game->player->pos_y))
		game->player->pos_x = new_x;
	if (is_valid_position(game->map, game->player->pos_x, buffer_y))
		game->player->pos_y = new_y;
}

t_texture	*get_wall_texture(t_game *game, t_ray *ray)
{
	int	door_index;

	if (game->map->map_data[ray->map_y][ray->map_x] == 'D')
	{
		door_index = is_door(game, ray->map_x, ray->map_y);
		if (door_index >= 0)
		{
			if (game->door_texture.img && game->door_texture.addr_mem)
			{
				return (&game->door_texture);
			}
			else
			{
				return (&game->north_texture);
			}
		}
	}
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (&game->east_texture);
		else
			return (&game->west_texture);
	}
	else
	{
		if (ray->step_y > 0)
			return (&game->south_texture);
		else
			return (&game->north_texture);
	}
}

int	load_door_texture(t_game *game, char *door_texture_path)
{
	printf("Trying to load door texture: %s\n", door_texture_path);
	game->door_texture.img = mlx_xpm_file_to_image(game->mlx_data->mlx,
													door_texture_path,
													&game->door_texture.width,
													&game->door_texture.height);
	if (!game->door_texture.img)
	{
		printf("Failed to load door texture from: %s\n", door_texture_path);
		return (0);
	}
	game->door_texture.addr_mem = mlx_get_data_addr(game->door_texture.img,
													&game->door_texture.bpp,
													&game->door_texture.len_line,
													&game->door_texture.endian);
	if (!game->door_texture.addr_mem)
	{
		printf("Failed to get door texture data\n");
		mlx_destroy_image(game->mlx_data->mlx, game->door_texture.img);
		game->door_texture.img = NULL;
		return (0);
	}
	printf("SUCCESS: Door texture loaded (%dx%d)\n",
			game->door_texture.width,
			game->door_texture.height);
	return (1);
}
