
#include "../cub3d.h"
#include "parse.h"

void	chose_color(t_var5 *var, t_game *game)
{
	var->color = 0x000000;
	var->c = game->map->map_data[var->mi][var->mj];
	if (var->c == '1')
		var->color = 0x808080;
	else
		var->color = ((game->map->flor.r << 16) | (game->map->flor.g << 8) | (game->map->flor.b));
}

void	draw_mini_map(t_game *game, t_var5 *var)
{
	var->py = 0;
	while (var->py < PIXEL_SIZE)
	{
		var->px = 0;
		while (var->px < PIXEL_SIZE)
		{
			put_pixel_to_image(game->img,
								(var->mj * 8 + var->px) + MIN_MAP,
								(var->mi * 8 + var->py) + MIN_MAP,
								var->color);
			var->px++;
		}
		var->py++;
	}
}
