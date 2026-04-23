/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:35:01 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/08 21:35:11 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_game_textures(t_game *game)
{
	if (!init_textures(game))
	{
		printf("Error: Failed to load textures\n");
		return (1);
	}
	return (0);
}

int	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
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
		if (!load_door_texture(game, "BONUS/pics/d.xpm"))
		{
			printf("Error: Failed to load door texture\n");
			return (1);
		}
	}
	return (0);
}
