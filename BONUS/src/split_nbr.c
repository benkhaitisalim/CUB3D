/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:27:55 by taya              #+#    #+#             */
/*   Updated: 2025/10/31 22:40:56 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

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
	if (extract_color_values(line, &var) != 0)
		return (1);
	if (parse_floor_color(&var, c, store) != 0)
		return (free_tmp_array(var.tmp, var.color), 1);
	if (parse_celing_color(&var, c, store) != 0)
		return (free_tmp_array(var.tmp, var.color), 1);
	return (free(var.tmp), 0);
}
