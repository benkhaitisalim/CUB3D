/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:49:54 by taya              #+#    #+#             */
/*   Updated: 2025/10/31 14:50:18 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_player(t_var_check *var)
{
	var->x = 0;
	while (var->x < var->len)
	{
		if (is_player_char(var->row[var->x]))
		{
			var->player_count++;
		}
		var->x++;
	}
	printf("there is : %d\n", var->player_count);
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

int	copy_double_arr(t_map *map, t_var_check *var)
{
	int	i;

	i = 0;
	var->copy = malloc(sizeof(char *) * (map->height + 1));
	if (!var->copy || !map->map_data)
		return (1);
	while (i < map->height)
	{
		var->copy[i] = ft_strdup(map->map_data[i]);
		if (!var->copy[i])
		{
			return (1);
		}
		i++;
	}
	var->copy[i] = NULL;
	return (0);
}
