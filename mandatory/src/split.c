/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:40 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/31 22:39:00 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

static int	in_range_255(int v)
{
	return (v >= 0 && v <= 255);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_floor_color(t_var3 *var, char c, t_map *store)
{
	if (c == 'F')
	{
		if (!var->tmp[0] || !var->tmp[1] || !var->tmp[2])
			return (1);
		if (!is_valid_number(var->tmp[0]) || !is_valid_number(var->tmp[1])
			|| !is_valid_number(var->tmp[2]))
			return (1);
		store->flor.r = ft_atoi(var->tmp[0]);
		store->flor.g = ft_atoi(var->tmp[1]);
		store->flor.b = ft_atoi(var->tmp[2]);
		if (!in_range_255(store->flor.r) || !in_range_255(store->flor.g)
			|| !in_range_255(store->flor.b))
			return (1);
		free(var->tmp[0]);
		free(var->tmp[1]);
		free(var->tmp[2]);
	}
	return (0);
}

int	parse_celing_color(t_var3 *var, char c, t_map *store)
{
	if (c == 'C')
	{
		if (!var->tmp[0] || !var->tmp[1] || !var->tmp[2])
			return (1);
		if (!is_valid_number(var->tmp[0]) || !is_valid_number(var->tmp[1])
			|| !is_valid_number(var->tmp[2]))
			return (1);
		store->celing.r = ft_atoi(var->tmp[0]);
		store->celing.g = ft_atoi(var->tmp[1]);
		store->celing.b = ft_atoi(var->tmp[2]);
		if (!in_range_255(store->celing.r) || !in_range_255(store->celing.g)
			|| !in_range_255(store->celing.b))
			return (1);
		free(var->tmp[0]);
		free(var->tmp[1]);
		free(var->tmp[2]);
	}
	return (0);
}

int	to_the_next_word(char *line, t_var3 *var)
{
	var->index = 0;
	while (line[var->i + var->index] && ft_isdigit(line[var->i + var->index]))
		var->index++;
	var->fill = 0;
	var->tmp[var->color] = malloc(sizeof(char) * (var->index + 1));
	if (!var->tmp[var->color])
		return (1);
	while (var->fill < var->index)
	{
		var->tmp[var->color][var->fill] = line[var->i + var->fill];
		var->fill++;
	}
	var->tmp[var->color][var->fill] = '\0';
	while (line[var->i + var->index] && ft_isspace(line[var->i + var->index])
		&& (line[var->i + var->index] != ','))
		var->index++;
	var->color++;
	return (var->index);
}
