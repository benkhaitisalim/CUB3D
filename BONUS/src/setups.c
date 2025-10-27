/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:17:54 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 00:17:55 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int	setup_map(t_map **map, char *filename)
{
	int	fd;

	fd = 0;
	*map = malloc(sizeof(t_map));
	if (!*map)
		return (1);
	init_map(*map);
	if (initialization_map(*map, fd, filename) != 0)
	{
		free(*map);
		return (1);
	}
	printf("Parsing Map it Good :) \n");
	return (0);
}

int	setup_player(t_player **player, t_map *map, t_mlx_data *data)
{
	int	result;

	*player = malloc(sizeof(t_player));
	if (!*player)
		return (error("Failed to allocate player"));
	result = init_player(*player, map, data);
	if (result == 2)
	{
		if (init_player(*player, map, data) == 1)
			error("Player not found");
		else
			error("Player direction not found");
	}
	return (0);
}

int	setup_image(t_img **img, t_mlx_data *data)
{
	*img = malloc(sizeof(t_img));
	if (!*img)
		return (1);
	(*img)->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!(*img)->img)
		return (1);
	(*img)->addr_mem = mlx_get_data_addr((*img)->img, &(*img)->bpp,
			&(*img)->len_line, &(*img)->endian);
	(*img)->width = SCREEN_WIDTH;
	(*img)->height = SCREEN_HEIGHT;
	return (0);
}

t_game	*setup_game(t_mlx_data *data, t_map *map, t_player *player, t_img *img)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx_data = data;
	game->map = map;
	game->player = player;
	game->img = img;
	game->tile_size = 50;
	return (game);
}
