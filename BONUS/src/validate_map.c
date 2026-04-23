/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:49:54 by taya              #+#    #+#             */
/*   Updated: 2025/11/07 22:47:02 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_player(t_var_check *var)
{
	var->x = 0;
	while (var->x < var->len)
	{
		if (is_player_char(var->row[var->x]))
			var->player_count++;
		var->x++;
	}
	return (0);
}

int	check_start_end_line(t_var_check *var, t_map *map)
{
	var->len = ft_strlen(var->row);
	if (var->y == 0 || var->y == map->height - 1)
	{
		var->x = 0;
		while (var->x < var->len)
		{
			if (var->row[var->x] != '1' && !ft_isspace(var->row[var->x]))
				return (1);
			var->x++;
		}
	}
	return (0);
}

static int	allocate_and_fill_rows(t_map *map, t_var_check *var, int max_len)
{
	int	i;
	int	len;

	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->map_data[i]);
		var->copy[i] = malloc(max_len + 1);
		if (!var->copy[i])
			return (error_msg("Error: memory allocation failed"), 1);
		ft_memcpy(var->copy[i], map->map_data[i], len);
		ft_memset(var->copy[i] + len, ' ', max_len - len);
		var->copy[i][max_len] = '\0';
		i++;
	}
	var->copy[i] = NULL;
	return (0);
}

int	copy_double_arr(t_map *map, t_var_check *var)
{
	int	i;
	int	len;
	int	max_len;

	if (!map->map_data)
		return (error_msg("Error: map data is missing"), 1);
	max_len = 0;
	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->map_data[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	var->copy = malloc(sizeof(char *) * (map->height + 1));
	if (!var->copy)
		return (error_msg("Error: memory allocation failed"), 1);
	return (allocate_and_fill_rows(map, var, max_len));
}
