/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:29:45 by taya              #+#    #+#             */
/*   Updated: 2025/11/08 21:30:10 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_win(t_mlx_data *data, t_img *img)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("init not ok \n");
		return (-1);
	}
	data->win = mlx_new_window(data->mlx, 1920, 720, "THE SECRET THRESORE");
	if (!data->win)
	{
		printf("init not ok \n");
		return (-1);
	}
	img->img = mlx_new_image(data->mlx, 800, 600);
	if (!img->img)
	{
		mlx_destroy_image(data->mlx, img->img);
		printf("init not ok \n");
		return (-1);
	}
	img->addr_mem = mlx_get_data_addr(img->img, &img->bpp, &img->len_line,
			&img->endian);
	return (1);
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dest = img->addr_mem + ((y * img->len_line) + (x * (img->bpp / 8)));
		*(unsigned int *)dest = color;
	}
}

int	init_mlx_data(t_mlx_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	return (0);
}

void	mlx_hooks_setup(t_game *game)
{
	mlx_hook(game->mlx_data->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_data->win, 3, 1L << 0, key_release, game);
	mlx_hook(game->mlx_data->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx_data->mlx, game_loop, game);
}

int	close_window(t_game *game)
{
	if (game->mlx_data->win)
		mlx_destroy_window(game->mlx_data->mlx, game->mlx_data->win);
	exit(0);
	return (0);
}
