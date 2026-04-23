/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:27:56 by taya              #+#    #+#             */
/*   Updated: 2025/11/01 16:17:32 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_3d(t_game *game)
{
	draw_floor_ceiling(game);
	draw_walls(game);
	mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->win,
		game->img->img, 0, 0);
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
