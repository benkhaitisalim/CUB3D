/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:20:35 by taya              #+#    #+#             */
/*   Updated: 2025/11/08 21:46:35 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

t_texture	*check_if_there_is_door(t_game *game)
{
	if (game->door_texture.img && game->door_texture.addr_mem)
		return (&game->door_texture);
	else
		return (&game->north_texture);
}

t_texture	*get_wall_texture(t_game *game, t_ray *ray)
{
	int	door_index;

	if (game->map->map_data[ray->map_y][ray->map_x] == 'D')
	{
		door_index = is_door(game, ray->map_x, ray->map_y);
		if (door_index >= 0)
			return (check_if_there_is_door(game));
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
	game->door_texture.img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			door_texture_path, &game->door_texture.width,
			&game->door_texture.height);
	if (!game->door_texture.img)
	{
		printf("Failed to load door texture from: %s\n", door_texture_path);
		return (0);
	}
	game->door_texture.addr_mem = mlx_get_data_addr(game->door_texture.img,
			&game->door_texture.bpp,
			&game->door_texture.len_line, &game->door_texture.endian);
	if (!game->door_texture.addr_mem)
	{
		printf("Failed to get door texture data\n");
		mlx_destroy_image(game->mlx_data->mlx, game->door_texture.img);
		game->door_texture.img = NULL;
		return (0);
	}
	return (1);
}
