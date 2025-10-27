/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:16:30 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 00:16:31 by bsalim           ###   ########.fr       */
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
int find_player_position1(char **map, int *pos_x, int *pos_y, int height)
{
    int i = 0;
    int j;
    int flag = 0;
    int skip;
    int len;

    if (!map || height <= 0)
        return 1;

    while (i < height)
    {
        if (!map[i])
            return 1;

        skip = skip_space(map[i]);
        len = ft_strlen(map[i]);
        j = 0;

        while (j + skip < len)
        {
            int idx = j + skip;

            if ((idx + 1 < len && ft_isspace(map[i][idx]) && map[i][idx + 1] == '0') ||
                (idx - 1 >= 0 && ft_isspace(map[i][idx]) && map[i][idx - 1] == '0'))
            {
                printf("Inside the map there is space with no wall at row %d, col %d\n", i, idx);
                return 1;
            }

            if (is_player_char(map[i][idx]))
            {
                *pos_x = idx;
                *pos_y = i;
                flag++;

                if (i + 1 < height && ft_isspace(map[i + 1][idx]))
                {
                    printf("Player below found space at row %d, col %d\n", i + 1, idx);
                    return 1;
                }
            }

            j++;
        }

        i++;
    }

    if (flag != 1)
    {
        if (flag == 0)
            printf("No player found in the map\n");
        else
            printf("More than one player found in the map\n");
        return 1;
    }

    return 0; 
}

int	ft_check_end_map(t_var_check *var, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (var->copy[i])
	{
		j = ft_strlen(var->copy[i]);
		if (i == map->height - 1)
		{
			k = 0;
			while (var->copy[i][k])
			{
				if (var->copy[i][k] != '1' && !ft_isspace(var->copy[i][k]))
				{
					printf("the start line should be space and '1' not '%c'\n",
							var->copy[i][k]);
					return (0);
				}
				if (ft_isspace(var->copy[i][k]) && (var->copy[i - 1][k] == '0'))
				{
					printf("map : end not closed '%c'\n", var->copy[i - 1][k]);
					return (0);
				}
				k++;
			}
		}
		while (j--)
		{
			if (var->copy[i][j] == '1')
			{
				break ;
			}
			else
			{
				printf("error : end map not ok : '%c'\n", var->copy[i][j]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_check_start_map(t_var_check *var)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	while (var->copy[i])
	{
		if (i == 0)
		{
			k = 0;
			while (var->copy[i][k])
			{
				if (var->copy[i][k] != '1' && !ft_isspace(var->copy[i][k]))
				{
					printf("the start line should be space and '1' not '%c'\n",
							var->copy[i][k]);
					return (0);
				}
				if (ft_isspace(var->copy[i][k]) && (var->copy[i + 1][k] == '0'))
				{
					printf("map start not closed '%c'\n", var->copy[i + 1][k]);
					return (0);
				}
				k++;
			}
		}
		j = skip_space(var->copy[i]);
		if (var->copy[i][j] == '1')
		{
			i++;
			continue ;
		}
		else
		{
			printf("error : strat map not ok : '%c'\n", var->copy[i][j]);
			return (0);
		}
	}
	return (1);
}
int	validate_map(t_map *map)
{
	t_var_check var;

	if (!map->no_textures || !map->so_textures || !map->we_textures
		|| !map->ea_textures)
	{
		printf("texture not found\n");
		return (1);
	}
	var.count_textur = map->count.no + map->count.so + map->count.ea + map->count.we;
	if(map->count.no > 1 ||map->count.so > 1 || map->count.ea > 1 || map->count.we > 1)
	{
		printf("texture daplicated \n");
		return 1;
	}
	if(var.count_textur > 4 || map->count_color > 2)
	{
		printf("number off texture or color not ok\n");
		return 1;
	}
	if (copy_double_arr(map, &var) != 0)
		return 1;
	int x, y;
	x = 0;
	y = 0;
	if (find_player_position1(var.copy, &x, &y,map->height) != 0)
		return 1;
	if (ft_check_start_map(&var) != 1 || ft_check_end_map(&var, map) != 1)
		return 1;
	int i = 0;
	var.player_count = 0;
	while (i < map->height)
	{
		var.row = ft_strdup(map->map_data[i]);
		int j = 0;
		while (var.row[j])
		{
			if (!is_map_char(var.row[j]) && !ft_isspace(var.row[j]))
			{
				printf("this is not map char '%c'\n", var.row[j]);
				return 1;
			}
			j++;
		}
		free(var.row);
		i++;
	}
	free_double_arr(var.copy);
	return (0);
}
