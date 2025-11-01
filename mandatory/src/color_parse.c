/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:14:59 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/31 22:19:13 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isspace(char c)
{
	return (c == ' ');
}

int	skip_name_color(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	while (line[i] && ft_isalpha(line[i]))
		i++;
	return (i);
}

int	find_color_and_parse_them(t_map *map, char *line, char c)
{
	int	skip;

	skip = skip_name_color(line);
	if (ft_split_number(map, line + skip, c) != 0)
	{
		printf("ddsda\n");
		return (1);
	}
	return (0);
}
