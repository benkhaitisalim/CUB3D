/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:27:55 by taya              #+#    #+#             */
/*   Updated: 2025/11/08 21:30:53 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',' && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_numbers(char *line)
{
	int	numbers;
	int	i;

	numbers = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		if (line[i])
		{
			numbers++;
			while (line[i] && ft_isdigit(line[i]))
				i++;
		}
	}
	return (numbers);
}

void	free_tmp_array(char **tmp, int color)
{
	while (color > 0)
		free(tmp[--color]);
	free(tmp);
}

int	extract_color_values(char *line, t_var3 *var)
{
	var->i = 0;
	while (line[var->i])
	{
		while (line[var->i] && ft_isspace(line[var->i]))
			var->i++;
		if (line[var->i])
		{
			if (is_valid_number(line) != 1)
				return (1);
			var->i += to_the_next_word(line, var);
			if (var->i == 1 && !var->tmp[var->color - 1])
				return (free_tmp_array(var->tmp, var->color), 1);
		}
		var->i++;
	}
	var->tmp[var->color] = NULL;
	return (0);
}

int	ft_split_number(t_map *store, char *line, char c)
{
	t_var3	var;

	var.numbers = count_numbers(line);
	var.tmp = malloc(sizeof(char *) * (var.numbers + 1));
	if (!var.tmp)
		return (1);
	var.color = 0;
	if (extract_color_values(line, &var)
		|| parse_floor_color(&var, c, store)
		|| parse_celing_color(&var, c, store))
		return (free_tmp_array(var.tmp, var.color), 1);
	free_tmp_array(var.tmp, var.color);
	return (0);
}
