/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:09:06 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/01 10:09:23 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	if (load_punch_texture(game) != 1)
		return (0);
	return (1);
}
