/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:37:29 by taya              #+#    #+#             */
/*   Updated: 2025/10/31 22:13:19 by bsalim           ###   ########.fr       */
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
		if (ray->map_y >= 0 && ray->map_y < game->map->height && ray->map_x >= 0
			&& ray->map_x < (int)strlen(game->map->map_data[ray->map_y])
			&& game->map->map_data[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player->pos_x + (1
					- ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player->pos_y + (1
					- ray->step_y) / 2) / ray->dir_y;
}

void	wall_height(t_game *game, t_ray *ray)
{
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = game->player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = game->player->pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

t_texture	*get_wall_texture(t_game *game, t_ray *ray)
{
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
