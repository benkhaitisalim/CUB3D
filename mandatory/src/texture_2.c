/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:17:30 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/08 17:18:05 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_game_textures(t_game *game)
{
	if (!init_textures(game))
	{
		ft_putstr_fd("Error: Failed to load textures\n", 2);
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
