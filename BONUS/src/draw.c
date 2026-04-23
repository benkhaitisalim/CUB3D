/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:34:15 by taya              #+#    #+#             */
/*   Updated: 2025/11/01 17:39:16 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

void	draw_3d(t_game *game)
{
	t_var5	var;
	int		offset_x;
	int		offset_y;

	draw_floor_ceiling(game);
	draw_walls(game);
	offset_x = (int)(game->player->pos_x * TILE_SIZE) - (MINIMAP_WIDTH / 2);
	offset_y = (int)(game->player->pos_y * TILE_SIZE) - (MINIMAP_HEIGHT / 2);
	draw_minimap_background(game);
	var.mi = 0;
	while (game->map->map_data[var.mi])
	{
		var.mj = 0;
		while (game->map->map_data[var.mi][var.mj])
		{
			chose_color(&var, game);
			draw_mini_map(game, &var, offset_x, offset_y);
			var.mj++;
		}
		var.mi++;
	}
	draw_player_centered(game);
	draw_gun(game);
	mlx_put_image_to_window(game->mlx_data->mlx,
		game->mlx_data->win, game->img->img, 0, 0);
}

void	draw_floor_ceiling(t_game *game)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				color = (game->map->celing.r << 16
						| game->map->celing.g << 8 | game->map->celing.b);
			else
				color = (game->map->flor.r << 16
						| game->map->flor.g << 8 | game->map->flor.b);
			put_pixel_to_image(game->img, x, y, color);
			x++;
		}
		y++;
	}
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

void	draw_walls(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		recasting(game, &ray, x);
		dda_algo(game, &ray);
		wall_height(game, &ray);
		draw_vertical_line(game, x, &ray);
		x++;
	}
}

void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	t_texture	*texture;
	double		step;
	int			y;
	int			color;
	char		*pixel;

	texture = get_wall_texture(game, ray);
	ray->tex_x = (int)(ray->wall_x * (double)texture->width);
	step = 1.0 * texture->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2)
		* step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (texture->height - 1);
		ray->tex_pos += step;
		pixel = texture->addr_mem + (ray->tex_y * texture->len_line + ray->tex_x
				* (texture->bpp / 8));
		color = *(int *)pixel;
		put_pixel_to_image(game->img, x, y, color);
		y++;
	}
}
