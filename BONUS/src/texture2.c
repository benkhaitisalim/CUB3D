/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:25:47 by taya              #+#    #+#             */
/*   Updated: 2025/11/05 16:16:58 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_punsh_text_part_1(t_game *game)
{
	game->gun_textures[0].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"BONUS/pics/SHOUT_NUMBER1.xpm",
			&game->gun_textures[0].width,
			&game->gun_textures[0].height);
	game->gun_textures[1].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"BONUS/pics/SHOUT_NUMBER2.xpm",
			&game->gun_textures[1].width,
			&game->gun_textures[1].height);
	game->gun_textures[2].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"BONUS/pics/SHOUT_NUMBER2.xpm",
			&game->gun_textures[2].width,
			&game->gun_textures[2].height);
}

void	init_punsh_text_part_2(t_game *game)
{
	game->gun_textures[3].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"BONUS/pics/SHOUT_NUMBER3.xpm",
			&game->gun_textures[3].width,
			&game->gun_textures[3].height);
	game->gun_textures[4].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"BONUS/pics/SHOUT_NUMBER4.xpm",
			&game->gun_textures[4].width,
			&game->gun_textures[4].height);
	game->gun_textures[5].img = mlx_xpm_file_to_image(game->mlx_data->mlx,
			"BONUS/pics/SHOUT_NUMBER5.xpm",
			&game->gun_textures[5].width,
			&game->gun_textures[5].height);
}

void	init_punsh_text(t_game *game)
{
	init_punsh_text_part_1(game);
	init_punsh_text_part_2(game);
	lets_get_the_punsh(game);
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
	init_punsh_text(game);
	return (1);
}
