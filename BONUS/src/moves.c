
#include "../cub3d.h"

// void	move_player_fb(t_game *game, int direction)
// {
// 	double	new_x;
// 	double	new_y;
// 	if (direction == 1)
// 	{
// 		new_x = game->player->pos_x + game->player->dir_x * MOVE_SPEED;
// 		new_y = game->player->pos_y + game->player->dir_y * MOVE_SPEED;
// 	}
// 	else
// 	{
// 		new_x = game->player->pos_x - game->player->dir_x * MOVE_SPEED;
// 		new_y = game->player->pos_y - game->player->dir_y * MOVE_SPEED;
// 	}
// 	if (is_valid_position(game->map, new_x, game->player->pos_y))
// 		game->player->pos_x = new_x;
// 	if (is_valid_position(game->map, game->player->pos_x, new_y))
// 		game->player->pos_y = new_y;
// }

// void	move_player_lf(t_game *game, int direction)
// {
// 	double	new_x;
// 	double	new_y;

// 	if (direction == 1)
// 	{
// 		new_x = game->player->pos_x - game->player->plane_x * MOVE_SPEED;
// 		new_y = game->player->pos_y - game->player->plane_y * MOVE_SPEED;
// 	}
// 	else
// 	{
// 		new_x = game->player->pos_x + game->player->plane_x * MOVE_SPEED;
// 		new_y = game->player->pos_y + game->player->plane_y * MOVE_SPEED;
// 	}
// 	if (is_valid_position(game->map, new_x, game->player->pos_y))
// 		game->player->pos_x = new_x;
// 	if (is_valid_position(game->map, game->player->pos_x, new_y))
// 		game->player->pos_y = new_y;
// }

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
