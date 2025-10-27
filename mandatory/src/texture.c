/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:36 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 00:15:37 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	load_north_texture(t_game *game)
{
	game->north_texture.img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			game->map->no_textures,
			&game->north_texture.width, &game->north_texture.height);
	if (!game->north_texture.img)
		return (0);
	game->north_texture.addr_mem = mlx_get_data_addr(game->north_texture.img,
			&game->north_texture.bpp,
			&game->north_texture.len_line, &game->north_texture.endian);
	return (1);
}

int	load_south_texture(t_game *game)
{
	game->south_texture.img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			game->map->so_textures,
			&game->south_texture.width, &game->south_texture.height);
	if (!game->south_texture.img)
		return (0);
	game->south_texture.addr_mem = mlx_get_data_addr(game->south_texture.img,
			&game->south_texture.bpp,
			&game->south_texture.len_line, &game->south_texture.endian);
	return (1);
}

int	load_west_texture(t_game *game)
{
	game->west_texture.img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			game->map->we_textures,
			&game->west_texture.width, &game->west_texture.height);
	if (!game->west_texture.img)
	{
		return (0);
	}
	game->west_texture.addr_mem = mlx_get_data_addr(game->west_texture.img,
			&game->west_texture.bpp,
			&game->west_texture.len_line, &game->west_texture.endian);
	return (1);
}

int	load_east_texture(t_game *game)
{
	game->east_texture.img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			game->map->ea_textures,
			&game->east_texture.width, &game->east_texture.height);
	if (!game->east_texture.img)
	{
		return (0);
	}
	game->east_texture.addr_mem = mlx_get_data_addr(game->east_texture.img,
			&game->east_texture.bpp,
			&game->east_texture.len_line, &game->east_texture.endian);
	return (1);
}

int	init_textures(t_game *game)
{
	if (load_north_texture(game) != 1)
		return (0);
	if (load_south_texture(game) != 1)
		return (0);
	if (load_west_texture(game) != 1)
		return (0);
	if (load_east_texture(game) != 1)
		return (0);
	return (1);
}
