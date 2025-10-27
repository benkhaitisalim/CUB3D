/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmat <swilmat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:15:11 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/27 15:00:04 by swilmat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../cub3d.h"
#include "parse.h"

static char *derive_base_dir(const char *av)
{
	char    *pos;
	size_t  len;
	char    *base;

	if (!av)
		return (ft_strdup("."));
	pos = ft_strnstr(av, "/maps/", ft_strlen(av));
	if (pos)
	{
		len = (size_t)(pos - av);
		return (ft_substr(av, 0, len));
	}
	len = ft_strlen(av);
	while (len > 0 && av[len - 1] != '/')
		len--;
	if (len == 0)
		return (ft_strdup("."));
	base = ft_substr(av, 0, len - 1);
	if (!base || base[0] == '\0')
	{
		if (base)
			free(base);
		return (ft_strdup("."));
	}
	return (base);
}

static int	finalize_map(t_map *map, int row)
{
	map->map_data[row] = NULL;
	map->height = row;
	return (0);
}

int	parse_map(t_map *map, int fd)
{
	int	capacity;
	int	row;

	capacity = 32;
	row = 0;
	map->map_data = malloc(sizeof(char *) * capacity);
	if (!map->map_data)
		return (1);
	if (process_file_lines(map, fd, &capacity, &row) != 0)
	{
		if (row > 0)
		{
			while (--row >= 0)
				free(map->map_data[row]);
		}
		free(map->map_data);
		map->map_data = NULL;
		if (map->no_textures)
			free(map->no_textures);
		if (map->so_textures)
			free(map->so_textures);
		if (map->we_textures)
			free(map->we_textures);
		if (map->ea_textures)
			free(map->ea_textures);
		return (1);
	}
	return (finalize_map(map, row));
}

int	process_file_lines(t_map *map, int fd, int *capacity, int *row)
{
	t_var	variable;

	variable.before_map = 1;
	while (1)
	{
		variable.line = get_next_line(fd);
		if (variable.line == NULL)
			break ;
		variable.i = remove_new_line(variable.line);
		if (variable.line[0] == '\0')
		{
			free(variable.line);
			if (variable.before_map)
				continue ;
			if (drain_after_map(fd) != 0)
				return (1);
			break ;
		}
		if (parse_split(map, capacity, row, &variable) != 0)
			return (1);
		free(variable.line);
	}
	return (0);
}

int	initialization_map(t_map *map, int fd, char *av)
{
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCannot open file\n");
		return (1);
	}
	if(ft_strnstr(av,".cub",3) != NULL)
	{
		printf("the file not end with the .cub\n");
		return (1);
	}
	map->base_dir = derive_base_dir(av);
	if (parse_map(map, fd) != 0)
	{
		printf("Error\n  Map not valid\n");
		close(fd);
		free(map->base_dir);
		map->base_dir = NULL;
		return (1);
	}
	close(fd);
	if (validate_map(map) != 0)
	{
		printf("Error\nMap not valid\n");
		if (map->map_data)
			free_double_arr(map->map_data);
		free(map->base_dir);
		if (map->no_textures)
			free(map->no_textures);
		if (map->so_textures)
			free(map->so_textures);
		if (map->we_textures)
			free(map->we_textures);
		if (map->ea_textures)
			free(map->ea_textures);
		map->base_dir = NULL;
		return (1);
	}
	printf("PARSING IS NADY ✅\n");
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
	return (s[len - 4] == '.' && s[len - 3] == 'x' && s[len - 2] == 'p'
		&& s[len - 1] == 'm');
}

char    *ft_get_texture(char *input)
{
    t_var2  var;
    int     arg_count;

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
