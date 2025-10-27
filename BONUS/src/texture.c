/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:16:42 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 00:16:43 by bsalim           ###   ########.fr       */
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
	game->gun_textures[0].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"pics/gun0.xpm", &game->gun_textures[0].width,
			&game->gun_textures[0].height);
	game->gun_textures[1].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"pics/gun1.xpm", &game->gun_textures[1].width,
			&game->gun_textures[1].height);
	game->gun_textures[2].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"pics/gun2.xpm", &game->gun_textures[2].width,
			&game->gun_textures[2].height);
	game->gun_textures[3].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"pics/gun3.xpm", &game->gun_textures[3].width,
			&game->gun_textures[3].height);
	int i = 0;
	while (i < 4)
	{
		if (game->gun_textures[i].img)
			game->gun_textures[i].addr_mem
				= mlx_get_data_addr(game->gun_textures[i].img,
					&game->gun_textures[i].bpp, &game->gun_textures[i].len_line,
					&game->gun_textures[i].endian);
		i++;
	}
	return (1);
}
