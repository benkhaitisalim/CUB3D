/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:38:53 by taya              #+#    #+#             */
/*   Updated: 2025/11/01 16:38:57 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

void	chose_color(t_var5 *var, t_game *game)
{
	var->color = 0x000000;
	var->c = game->map->map_data[var->mi][var->mj];
	if (var->c == '1')
		var->color = 0x808080;
	else
		var->color = ((game->map->flor.r << 16)
				| (game->map->flor.g << 8) | game->map->flor.b);
}

void	draw_minimap_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			put_pixel_to_image(game->img,
				MINIMAP_X + x, MINIMAP_Y + y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_mini_map(t_game *game, t_var5 *var, int offset_x, int offset_y)
{
	int	screen_x;
	int	screen_y;
	int	tile_screen_x;
	int	tile_screen_y;

	var->py = 0;
	while (var->py < TILE_SIZE)
	{
		var->px = 0;
		while (var->px < TILE_SIZE)
		{
			tile_screen_x = (var->mj * TILE_SIZE + var->px) - offset_x;
			tile_screen_y = (var->mi * TILE_SIZE + var->py) - offset_y;
			if (tile_screen_x >= 0 && tile_screen_x < MINIMAP_WIDTH
				&& tile_screen_y >= 0 && tile_screen_y < MINIMAP_HEIGHT)
			{
				screen_x = MINIMAP_X + tile_screen_x;
				screen_y = MINIMAP_Y + tile_screen_y;
				put_pixel_to_image(game->img, screen_x, screen_y, var->color);
			}
			var->px++;
		}
		var->py++;
	}
}

void	draw_player_centered(t_game *game)
{
	int	px;
	int	py;
	int	center_x;
	int	center_y;

	center_x = MINIMAP_X + (MINIMAP_WIDTH / 2);
	center_y = MINIMAP_Y + (MINIMAP_HEIGHT / 2);
	py = 0;
	while (py < TILE_SIZE)
	{
		px = 0;
		while (px < TILE_SIZE)
		{
			put_pixel_to_image(game->img, center_x - (TILE_SIZE / 2) + px,
				center_y - (TILE_SIZE / 2) + py, 0xFF0000);
			px++;
		}
		py++;
	}
}
