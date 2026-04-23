/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:26 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/08 20:21:26 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_space_near_zero(char **map, int i, int idx, int len)
{
	if ((idx + 1 < len && ft_isspace(map[i][idx]) && map[i][idx + 1] == '0')
		|| (idx - 1 >= 0 && ft_isspace(map[i][idx]) && map[i][idx - 1] == '0'))
		return (1);
	return (0);
}

int	check_space_near_tile(char **map, int i, int j, int height)
{
	if (map[i][j] == '0' || is_player_char(map[i][j]))
	{
		if ((i > 0 && ft_isspace(map[i - 1][j])) || (i + 1 < height
				&& ft_isspace(map[i + 1][j])) || (j > 0 && ft_isspace(map[i][j
					- 1])) || ft_isspace(map[i][j + 1]))
			return (1);
	}
	return (0);
}

int	process_row_chars(char **map, int i, int pos[2], int height)
{
	t_var6	var;

	var.s = skip_space(map[i]);
	var.len = ft_strlen(map[i]);
	var.flag = 0;
	var.j = -1;
	while (++var.j + var.s < var.len)
	{
		var.idx = var.j + var.s;
		if (check_space_near_zero(map, i, var.idx, var.len))
			return (-1);
		if (map[i][var.idx] == '0' || is_player_char(map[i][var.idx]))
		{
			if (check_space_near_tile(map, i, var.idx, height))
				return (-1);
			if (is_player_char(map[i][var.idx]))
			{
				pos[0] = var.idx;
				pos[1] = i;
				var.flag++;
			}
		}
	}
	return (var.flag);
}

int	validate_player_flag(int flag)
{
	if (flag == 0)
		return (1);
	if (flag > 1)
		return (1);
	return (0);
}

int	find_player_position1(char **map, int pos[2], int height)
{
	int	i;
	int	flag;
	int	row_flag;

	if (!map || height <= 0)
		return (1);
	i = 0;
	flag = 0;
	while (i < height)
	{
		if (!map[i])
			return (1);
		row_flag = process_row_chars(map, i, pos, height);
		if (row_flag == -1)
			return (1);
		flag += row_flag;
		i++;
	}
	if (validate_player_flag(flag) != 0)
		return (1);
	return (0);
}
