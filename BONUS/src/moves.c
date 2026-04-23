/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:36:00 by taya              #+#    #+#             */
/*   Updated: 2025/11/01 16:53:38 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_buffer(t_game *game, double new_x,
	double new_y, t_collision *col)
{
	col->new_x = new_x;
	col->new_y = new_y;
	if (new_x > game->player->pos_x)
		col->buffer_x = new_x + COLLISION_BUFFER;
	else
		col->buffer_x = new_x - COLLISION_BUFFER;
	if (new_y > game->player->pos_y)
		col->buffer_y = new_y + COLLISION_BUFFER;
	else
		col->buffer_y = new_y - COLLISION_BUFFER;
}

void	move_player_fb(t_game *game, int direction)
{
	double		new_x;
	double		new_y;
	t_collision	col;

	if (direction == 1)
	{
		new_x = game->player->pos_x + game->player->dir_x * MOVE_SPEED;
		new_y = game->player->pos_y + game->player->dir_y * MOVE_SPEED;
	}
	else
	{
		new_x = game->player->pos_x - game->player->dir_x * MOVE_SPEED;
		new_y = game->player->pos_y - game->player->dir_y * MOVE_SPEED;
	}
	calculate_buffer(game, new_x, new_y, &col);
	if (is_valid_position(game->map, col.buffer_x, game->player->pos_y))
		game->player->pos_x = col.new_x;
	if (is_valid_position(game->map, game->player->pos_x, col.buffer_y))
		game->player->pos_y = col.new_y;
}

void	move_player_lf(t_game *game, int direction)
{
	double		new_x;
	double		new_y;
	t_collision	col;

	if (direction == 1)
	{
		new_x = game->player->pos_x - game->player->plane_x * MOVE_SPEED;
		new_y = game->player->pos_y - game->player->plane_y * MOVE_SPEED;
	}
	else
	{
		new_x = game->player->pos_x + game->player->plane_x * MOVE_SPEED;
		new_y = game->player->pos_y + game->player->plane_y * MOVE_SPEED;
	}
	calculate_buffer(game, new_x, new_y, &col);
	if (is_valid_position(game->map, col.buffer_x, game->player->pos_y))
		game->player->pos_x = col.new_x;
	if (is_valid_position(game->map, game->player->pos_x, col.buffer_y))
		game->player->pos_y = col.new_y;
}

void	rotate_player(t_game *game, int direction)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	old_dir_x = game->player->dir_x;
	old_plane_x = game->player->plane_x;
	if (direction == 1)
		rot_speed = ROT_SPEED;
	else
		rot_speed = -ROT_SPEED;
	game->player->dir_x = game->player->dir_x * cos(rot_speed)
		- game->player->dir_y * sin(rot_speed);
	game->player->dir_y = old_dir_x * sin(rot_speed) + game->player->dir_y
		* cos(rot_speed);
	game->player->plane_x = game->player->plane_x * cos(rot_speed)
		- game->player->plane_y * sin(rot_speed);
	game->player->plane_y = old_plane_x * sin(rot_speed) + game->player->plane_y
		* cos(rot_speed);
}
