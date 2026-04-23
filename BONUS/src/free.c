/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:18:52 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/08 21:33:08 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cleanup_map_resources(t_map *map)
{
	if (map->map_data)
		free_double_arr(map->map_data);
	if (map->no_textures)
		free(map->no_textures);
	if (map->so_textures)
		free(map->so_textures);
	if (map->we_textures)
		free(map->we_textures);
	if (map->ea_textures)
		free(map->ea_textures);
}

void	free_double_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_textures(t_game *game)
{
	if (game->north_texture.img)
		mlx_destroy_image(game->mlx_data->mlx, game->north_texture.img);
	if (game->south_texture.img)
		mlx_destroy_image(game->mlx_data->mlx, game->south_texture.img);
	if (game->west_texture.img)
		mlx_destroy_image(game->mlx_data->mlx, game->west_texture.img);
	if (game->east_texture.img)
		mlx_destroy_image(game->mlx_data->mlx, game->east_texture.img);
}

void	free_doors(t_game *game)
{
	if (game->doors)
	{
		free(game->doors);
		game->doors = NULL;
		game->door_count = 0;
	}
	if (game->door_texture.img)
	{
		mlx_destroy_image(game->mlx_data->mlx, game->door_texture.img);
		game->door_texture.img = NULL;
		game->door_texture.addr_mem = NULL;
	}
}

void	cleanup_game(t_game *game, t_player *player, t_img *img, t_map *map)
{
	if (game && game->map && game->map->map_data)
		free_double_arr(game->map->map_data);
	free_textures(game);
	if (map)
	{
		free(map->no_textures);
		free(map->so_textures);
		free(map->we_textures);
		free(map->ea_textures);
	}
	free(game);
	free(player);
	free(img);
	free(map);
}
