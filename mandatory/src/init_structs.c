/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:04 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/31 22:15:47 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

void	init_rays(t_ray *rays)
{
	rays->dir_x = 0.0;
	rays->dir_y = 0.0;
	rays->map_x = 0;
	rays->map_y = 0;
	rays->delta_x = 0.0;
	rays->delta_y = 0.0;
	rays->side_x = 0.0;
	rays->side_y = 0.0;
	rays->step_x = 0;
	rays->step_y = 0;
	rays->hit = 0;
	rays->side = 0;
	rays->perp_wall_dist = 0.0;
	rays->wall_dist = 0.0;
	rays->line_height = 0;
	rays->draw_start = 0;
	rays->draw_end = 0;
	rays->wall_x = 0.0;
	rays->tex_x = 0;
	rays->tex_num = 0;
}

void	init_keys(t_game *game)
{
	game->keys.w = 0;
	game->keys.s = 0;
	game->keys.a = 0;
	game->keys.d = 0;
	game->keys.left = 0;
	game->keys.right = 0;
}

int	init_map(t_map *map)
{
	map->count.f = 0;
	map->count.c = 0;
	map->count.ea = 0;
	map->count.we = 0;
	map->count.so = 0;
	map->count.no = 0;
	map->count_color = 0;
	map->ea_textures = NULL;
	map->we_textures = NULL;
	map->so_textures = NULL;
	map->no_textures = NULL;
	map->base_dir = NULL;
	map->player = NULL;
	map->map_data = NULL;
	map->height = 0;
	map->width = 0;
	return (0);
}

void	init_player_var(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
}
