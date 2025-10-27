/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:18:35 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 00:18:36 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

static void	blit_texture_to_image(t_game *game, t_texture *tex, int dst_x,
		int dst_y)
{
	int		x;
	int		y;
	int		color;
	char	*src;

	if (!tex || !tex->img || !tex->addr_mem)
		return ;
	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			src = tex->addr_mem + (y * tex->len_line + x * (tex->bpp / 8));
			color = *(int *)src;
			if ((color & 0xFF) != 0)
				put_pixel_to_image(game->img, dst_x + x, dst_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_gun(t_game *game)
{
	t_player	*p;
	int			frame_index;
	int			dst_x;
	int			dst_y;

	p = game->player;
	if (p->shooting)
	{
		p->gun_tick++;
		if (p->gun_tick >= p->gun_frame_delay)
		{
			p->gun_tick = 0;
			p->gun_frame++;
			if (p->gun_frame >= p->gun_frame_max)
			{
				p->gun_frame = 0;
				p->shooting = 0;
			}
		}
	}
	frame_index = p->gun_frame % p->gun_frame_max;
	dst_x = ((SCREEN_WIDTH / 2) - 64);
	dst_y = SCREEN_HEIGHT - 160;
	blit_texture_to_image(game, &game->gun_textures[frame_index], dst_x, dst_y);
}
