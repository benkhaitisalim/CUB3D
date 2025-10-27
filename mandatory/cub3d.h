/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:30 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 00:15:31 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/parse.h"
# include "libft/libft.h"
# include <ctype.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define BUFFER_SIZE 42
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49
# define KEY_ESC 53
# define MOVE_SPEED 0.08
# define ROT_SPEED 0.05

# define MIN_MAP 29
# define PIXEL_SIZE 10

typedef struct s_var_check
{
	int			count_textur;
	int			player_count;
	int			y;
	int			len;
	int			x;
	char		*row;
	char		**copy;
	int			count_color;
}				t_var_check;

typedef struct s_texture_check
{
    int no;
    int so;
    int we;
    int ea;
    int f;
    int c;
} t_texture_check;

typedef struct s_door
{
	int			x;
	int			y;
	int			is_opening;
	float		open_progress;
	float		animation_speed;
}				t_door;

typedef struct s_var_line
{
	char		*line;
	int			i;
	char		*tmp;
	int			size;

}				t_var_line;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
	int			mouse_x;
	int			mouse_locked;
}				t_keys;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_img
{
	void		*img;
	int			bpp;
	int			height;
	int			width;
	int			len_line;
	int			endian;
	char		*addr_mem;
}				t_img;

typedef struct s_mlx_data
{
	void		*mlx;
	t_img		*img;
	void		*win;
}				t_mlx_data;

typedef struct s_texture
{
	void		*img;
	int			bpp;
	int			height;
	int			width;
	int			len_line;
	int			endian;
	char		*addr_mem;
}				t_texture;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			shooting;
	int			gun_frame;
	int			gun_tick;
	int			gun_frame_max;
	int			gun_frame_delay;
}				t_player;

typedef struct s_map
{
	char		**map_data;
	int			height;
	int			width;
	char		*base_dir;
	char		*no_textures;
	char		*so_textures;
	t_player	*player;
	char		*we_textures;
	char		*ea_textures;
	int			texture_count;
	t_color		flor;
	t_color		celing;
	t_texture	*textur;
	t_texture_check count;
	int			count_color;
}				t_map;

typedef struct s_game
{
	t_mlx_data	*mlx_data;
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	east_texture;
	t_texture	gun_textures[4];
	t_texture	west_texture;
	t_map		*map;
	t_keys		keys;
	t_player	*player;
	t_img		*img;
	t_door		*doors;
	int			door_count;
	float		door_trigger_distance;
	t_texture	door_texture;
	int			tile_size;
}				t_game;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		wall_dist;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	int			tex_num;
}				t_ray;
int				initialization_map(t_map *map, int fd, char *av);
char			*get_next_line(int fd);
void			draw_floor_ceiling(t_game *game);
void			draw_walls(t_game *game);
int				create_win(t_mlx_data *data, t_img *img);
void			put_pixel_to_image(t_img *img, int x, int y, int color);
void			init_player_var(t_player *player);
int				find_player_position(char **map, double *pos_x, double *pos_y);
int				find_player_direction(char **map, double *dir_x, double *dir_y);
void			set_camera_plane(double dir_x, double dir_y, double *plane_x,
					double *plane_y);
int				is_valid_position(t_map *map, double x, double y);
void			move_player_fb(t_game *game, int direction);
void			move_player_lf(t_game *game, int direction);
void			rotate_player(t_game *game, int direction);
int				key_press(int keycode, t_game *game);
int				close_window(t_game *game);
void			init_rays(t_ray *rays);
void			recasting(t_game *game, t_ray *ray, int x);
void			dda_algo(t_game *game, t_ray *ray);
void			wall_height(t_game *game, t_ray *ray);
t_texture		*get_wall_texture(t_game *game, t_ray *ray);
void			draw_vertical_line(t_game *game, int x, t_ray *ray);
void			draw_3d(t_game *game);
int				init_textures(t_game *game);
int				skip_space(char *line);
void			free_textures(t_game *game);
int				game_loop(t_game *game);
int				key_release(int keycode, t_game *game);
void			init_keys(t_game *game);
int				is_map_char(char c);
int				is_player_char(char c);
int				ft_isspace(char c);
int				skip_space(char *line);
int				init_mlx_data(t_mlx_data *data);
void			free_double_arr(char **arr);
int				init_map(t_map *map);
int				parse_map(t_map *map, int fd);
char			*ft_get_texture(char *input);
int				find_color_and_parse_them(t_map *map, char *line, char c);
int				check_diagonal(char *input);

void			*xrealloc(void *ptr, size_t new_count, size_t elem);
int				validate_map(t_map *map);
int				error(char *msg);
int				ft_split_number(t_map *store, char *line, char c);
int				ft_word(char *line);
void			mlx_hooks_setup(t_game *game);
int				setup_map(t_map **map, char *filename);
int				setup_player(t_player **player, t_map *map, t_mlx_data *data);
int				setup_image(t_img **img, t_mlx_data *data);
t_game			*setup_game(t_mlx_data *data, t_map *map, t_player *player,
					t_img *img);
int				init_player(t_player *player, t_map *map, t_mlx_data *data);
void	cleanup_game(t_game *game,
					t_player *player,
					t_img *img,
					t_map *map);

float			distance_calcul(float x1, float y1, float x2, float y2);
void			parsing_doors(t_game *game, t_map *map);
void			update_door(t_game *game);
int				is_door(t_game *game, int x, int y);
int				door_passable(t_game *game, int door_index);
void			dda_algo(t_game *game, t_ray *ray);
int				is_valid_pos_with_doors(t_game *game, t_map *map, double x,
					double y);
void			move_player_fb(t_game *game, int direction);
void			move_player_lf(t_game *game, int direction);
void			free_doors(t_game *game);
int				load_door_texture(t_game *game, char *door_texture_path);
int				mouse_move(int x, int y, t_game *game);
#endif