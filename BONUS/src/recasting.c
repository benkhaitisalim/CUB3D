/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:42:04 by taya              #+#    #+#             */
/*   Updated: 2025/11/01 17:38:21 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	recasting_rays(t_game *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dir_x = game->player->dir_x + (game->player->plane_x * camera_x);
	ray->dir_y = game->player->dir_y + (game->player->plane_y * camera_x);
	ray->map_x = (int)game->player->pos_x;
	ray->map_y = (int)game->player->pos_y;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
}

void	recasting(t_game *game, t_ray *ray, int x)
{
	recasting_rays(game, ray, x);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (game->player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - game->player->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (game->player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - game->player->pos_y) * ray->delta_y;
	}
	ray->hit = 0;
}

void	open_door_progress_simulation(t_game *game, t_ray *ray,
	int index_door, int hit_chance)
{
	index_door = is_door(game, ray->map_x, ray->map_y);
	if (index_door >= 0)
	{
		if (game->doors[index_door].open_progress < 0.2)
			ray->hit = 1;
		else if (game->doors[index_door].open_progress < 0.8)
		{
			hit_chance = (int)((1.0
						- game->doors[index_door].open_progress) * 100);
			if ((rand() % 100) < hit_chance)
				ray->hit = 1;
		}
	}
	else
		ray->hit = 1;
}

void	add_door_in_dda_algo(t_game *game, t_ray *ray)
{
	int		index_door;
	char	check;
	int		hit_chance;

	index_door = 0;
	hit_chance = 0;
	if (ray->map_y >= 0 && ray->map_y < game->map->height
		&& ray->map_x >= 0
		&& ray->map_x < (int)strlen(game->map->map_data[ray->map_y]))
	{
		check = game->map->map_data[ray->map_y][ray->map_x];
		if (check == '1')
			ray->hit = 1;
		else if (check == 'D')
			open_door_progress_simulation(game, ray, index_door, hit_chance);
	}
	else
		ray->hit = 1;
}

void	dda_algo(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
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
		add_door_in_dda_algo(game, ray);
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player->pos_x + (1
					- ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player->pos_y + (1
					- ray->step_y) / 2) / ray->dir_y;
}
