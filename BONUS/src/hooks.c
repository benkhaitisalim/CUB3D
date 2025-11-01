/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:06:41 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/01 10:15:01 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx_data->mlx, game->mlx_data->win);
		exit(0);
	}
	else if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_SPACE)
		game->player->shooting = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	int	delta_x;
	int	i;

	(void)y;
	if (!game->keys.mouse_locked)
	{
		game->keys.mouse_x = x;
		game->keys.mouse_locked = 1;
		return (0);
	}
	delta_x = x - game->keys.mouse_x;
	if (delta_x > 0)
	{
		i = 0;
		while (i++ < delta_x)
			rotate_player(game, 1);
	}
	else if (delta_x < 0)
	{
		i = 0;
		while (i++ < -delta_x)
			rotate_player(game, -1);
	}
	if (delta_x != 0)
		draw_3d(game);
	game->keys.mouse_x = x;
	if (x < 10 || x > SCREEN_WIDTH - 10)
	{
		mlx_mouse_move(game->mlx_data->win,
			SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		game->keys.mouse_x = SCREEN_WIDTH / 2;
	}
	return (0);
}

int	game_loop(t_game *game)
{
	update_door(game);
	if (game->keys.w)
		move_player_fb(game, 1);
	if (game->keys.s)
		move_player_fb(game, -1);
	if (game->keys.a)
		move_player_lf(game, 1);
	if (game->keys.d)
		move_player_lf(game, -1);
	if (game->keys.right)
		rotate_player(game, 1);
	if (game->keys.left)
		rotate_player(game, -1);
	draw_gun(game);
	draw_3d(game);
	return (0);
}
