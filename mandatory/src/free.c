/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:14:30 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 00:14:31 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_double_arr(char **arr)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		free(arr[j]);
		j++;
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
		free(map->base_dir);
	}
	free(game);
	free(player);
	free(img);
	free(map);
}
