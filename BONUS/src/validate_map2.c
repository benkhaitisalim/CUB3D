/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:46:25 by taya              #+#    #+#             */
/*   Updated: 2025/11/08 20:35:22 by bsalim           ###   ########.fr       */
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
			return (0);
		if (i > 0 && var->copy[i - 1] && ft_isspace(var->copy[i][k])
			&& var->copy[i - 1][k] == '0')
			return (0);
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
			break ;
		if (!ft_isspace(line[j]))
			return (0);
	}
	return (1);
}

int	ft_check_end_map(t_var_check *var, t_map *map)
{
	int	i;

	i = 0;
	while (var->copy[i])
	{
		if (i == map->height - 1 && !check_last_line(var, i))
			return (0);
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
			return (0);
		if (var->copy[1] && ft_isspace(var->copy[0][k])
			&& var->copy[1][k] == '0')
			return (0);
		k++;
	}
	return (1);
}

int	ft_check_start_map(t_var_check *var)
{
	int	i;
	int	j;

	if (!check_first_line(var))
		return (0);
	i = 1;
	while (var->copy[i])
	{
		j = skip_space(var->copy[i]);
		if (var->copy[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}
