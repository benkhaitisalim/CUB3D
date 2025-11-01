/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:46:25 by taya              #+#    #+#             */
/*   Updated: 2025/10/31 22:51:00 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_last_line(t_var_check *var, int i)
{
	int	k;

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
	return (1);
}

int	check_line_ends_with_wall(char *line)
{
	int	j;

	j = ft_strlen(line);
	while (j--)
	{
		if (line[j] == '1')
		{
			break ;
		}
		else
		{
			printf("error : end map not ok : '%c'\n", line[j]);
			return (0);
		}
	}
	return (1);
}

int	ft_check_end_map(t_var_check *var, t_map *map)
{
	int	i;

	i = 0;
	while (var->copy[i])
	{
		if (i == map->height - 1)
		{
			if (!check_last_line(var, i))
				return (0);
		}
		if (!check_line_ends_with_wall(var->copy[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_first_line(t_var_check *var)
{
	int	k;

	k = 0;
	while (var->copy[0][k])
	{
		if (var->copy[0][k] != '1' && !ft_isspace(var->copy[0][k]))
		{
			printf("the start line should be space and '1' not '%c'\n",
				var->copy[0][k]);
			return (0);
		}
		if (ft_isspace(var->copy[0][k]) && (var->copy[1][k] == '0'))
		{
			printf("map start not closed '%c'\n", var->copy[1][k]);
			return (0);
		}
		k++;
	}
	return (1);
}

int	ft_check_start_map(t_var_check *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->copy[i])
	{
		if (i == 0)
		{
			if (!check_first_line(var))
				return (0);
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
