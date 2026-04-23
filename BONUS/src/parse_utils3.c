/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:26:59 by taya              #+#    #+#             */
/*   Updated: 2025/11/08 21:33:18 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parse.h"

int	open_and_validate_file(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCannot open file\n");
		return (-1);
	}
	if (ft_strnstr(av, ".cub", 3) != NULL)
	{
		printf("the file not end with the .cub\n");
		close(fd);
		return (-1);
	}
	return (fd);
}

int	initialization_map(t_map *map, int fd, char *av)
{
	fd = open_and_validate_file(av);
	if (fd == -1)
		return (1);
	if (parse_map(map, fd) != 0)
	{
		printf("Error : Somthing on File not okey\n");
		close(fd);
		return (1);
	}
	close(fd);
	if (validate_map(map) != 0)
	{
		printf("Error : Map || texture || color not valid \n");
		cleanup_map_resources(map);
		return (1);
	}
	return (0);
}

static int	ends_with_xpm(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len < 4)
		return (0);
	return (s[len - 4] == '.' && s[len - 3] == 'x' && s[len - 2] == 'p' && s[len
			- 1] == 'm');
}

char	*ft_get_texture(char *input)
{
	t_var2	var;
	int		arg_count;

	var.text = my_split(input);
	arg_count = 0;
	while (var.text[arg_count])
		arg_count++;
	if (arg_count != 2)
	{
		free_double_arr(var.text);
		return (NULL);
	}
	var.i = 1;
	var.result = ft_strtrim(var.text[1], " \t");
	free_double_arr(var.text);
	if (!var.result)
		return (NULL);
	if (!ends_with_xpm(var.result))
	{
		free(var.result);
		return (NULL);
	}
	return (var.result);
}
