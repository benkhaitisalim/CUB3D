/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:50 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/08 21:29:50 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	run_the_game(t_mlx_data *data, t_game *game)
{
	init_keys(game);
	mlx_hooks_setup(game);
	draw_3d(game);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_mlx_data	data;
	t_map		*map;
	t_player	*player;
	t_img		*img;
	t_game		*game;

	if (ac != 2)
		return (printf("number off arguments is more than tow\n"), 1);
	if (setup_map(&map, av[1]) != 0 || init_mlx_data(&data) != 0)
		return (1);
	if (setup_player(&player, map, &data) != 0)
		return (1);
	if (setup_image(&img, &data) != 0)
		return (1);
	game = setup_game(&data, map, player, img);
	if (!game)
		return (error("Failed to allocate game structure"), 1);
	if (init_game_textures(game) != 0)
	{
		free_befor_run_the_game(game, map, player, img);
		return (1);
	}
	run_the_game(&data, game);
	cleanup_game(game, player, img, map);
	return (0);
}
