/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:18:23 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 11:08:43 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	ll()
{
	system("leaks cub3D");
}
int	init_game_textures(t_game *game)
{
	if (!init_textures(game))
	{
		ft_putstr_fd("Error: Failed to load textures\n", 2);
		return (1);
	}
	return (0);
}

int	error(char *msg)
{
	printf("Error: %s\n", msg);
	return (1);
}

int	init_door_system(t_game *game)
{
	parsing_doors(game, game->map);
	if (game->door_count > 0)
	{
		if (!load_door_texture(game, "pics/d.xpm"))
		{
			ft_putstr_fd("Error: Failed to load door texture\n", 2);
		}
	}
	printf("Initialized %d doors in the map\n", game->door_count);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_data	data;
	t_map		*map;
	t_player	*player;
	t_img		*img;
	t_game		*game;

	// atexit(ll);
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
		return (error("Failed to allocate game structure"));
	if (init_game_textures(game) != 0)
		return (1);
	if (init_door_system(game) != 0)
		return (1);
	init_keys(game);
	mlx_hooks_setup(game);
	draw_3d(game);
	mlx_loop(data.mlx);
	cleanup_game(game, player, img, map);
	return (0);
}
