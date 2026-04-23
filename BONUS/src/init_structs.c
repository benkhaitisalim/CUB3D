/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:18:30 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/01 16:41:46 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	game->keys.mouse_x = SCREEN_WIDTH / 2;
	game->keys.mouse_locked = 0;
}

int	init_map(t_map *map)
{
	if (!map)
		return (1);
	map->map_data = NULL;
	map->height = 0;
	map->width = 0;
	map->no_textures = NULL;
	map->so_textures = NULL;
	map->we_textures = NULL;
	map->ea_textures = NULL;
	map->player = NULL;
	map->texture_count = 0;
	map->flor.r = -1;
	map->flor.g = -1;
	map->flor.b = -1;
	map->celing.r = -1;
	map->celing.g = -1;
	map->celing.b = -1;
	map->textur = NULL;
	map->count.no = 0;
	map->count.so = 0;
	map->count.we = 0;
	map->count.ea = 0;
	map->count.f = 0;
	map->count.c = 0;
	return (map->count_color = 0, 0);
}

void	init_player_var(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->shooting = 0;
	player->gun_frame = 0;
	player->gun_tick = 0;
	player->gun_frame_max = 4;
	player->gun_frame_delay = 6;
}
