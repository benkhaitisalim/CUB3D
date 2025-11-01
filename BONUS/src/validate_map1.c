/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:26 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/31 22:51:14 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_space_near_zero(char **map, int i, int idx, int len)
{
	if ((idx + 1 < len && ft_isspace(map[i][idx]) && map[i][idx + 1] == '0')
		|| (idx - 1 >= 0 && ft_isspace(map[i][idx]) && map[i][idx - 1] == '0'))
	{
		printf("Inside the map there is space with no wall at row %d,col %d\n",
			i, idx);
		return (1);
	}
	return (0);
}

int	check_player_space_below(char **map, int i, int idx, int height)
{
	if (i + 1 < height && ft_isspace(map[i + 1][idx]))
	{
		printf("Player below found space at row %d, col %d\n", i + 1, idx);
		return (1);
	}
	return (0);
}

int	process_row_chars(char **map, int i, int pos[2], int height)
{
	int	j;
	int	s;
	int	len;
	int	idx;
	int	flag;

	s = skip_space(map[i]);
	len = ft_strlen(map[i]);
	flag = 0;
	j = -1;
	while (++j + s < len)
	{
		idx = j + s;
		if (check_space_near_zero(map, i, idx, len))
			return (-1);
		if (is_player_char(map[i][idx]))
		{
			pos[0] = idx;
			pos[1] = i;
			flag++;
			if (check_player_space_below(map, i, idx, height))
				return (-1);
		}
	}
	return (flag);
}

int	validate_player_flag(int flag)
{
	if (flag != 1)
	{
		if (flag == 0)
			printf("No player found in the map\n");
		else
			printf("More than one player found in the map\n");
		return (1);
	}
	return (0);
}

int	find_player_position1(char **map, int pos[2], int height)
{
	int	i;
	int	flag;
	int	row_flag;

	i = 0;
	flag = 0;
	if (!map || height <= 0)
		return (1);
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
	return (validate_player_flag(flag));
}
