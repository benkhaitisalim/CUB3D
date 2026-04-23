/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:41:41 by bsalim            #+#    #+#             */
/*   Updated: 2025/11/05 16:38:07 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_map	t_map;

typedef struct s_var
{
	char				*line;
	int					i;
	int					before_map;
}						t_var;
typedef struct s_var1
{
	int					valid;
	int					ci;
	int					skip;
	int					new_cap;
	char				**tmp;
}						t_var1;

typedef struct s_var2
{
	char				**text;
	char				*result;
	int					i;
	int					j;
}						t_var2;

typedef struct s_var3
{
	int					i;
	int					numbers;
	char				**tmp;
	int					color;
	int					fill;
	int					index;
}						t_var3;

typedef struct s_var4
{
	char				**tmp;
	int					word;
	int					index;
	int					i;
	int					words;
	int					fill;
}						t_var4;

typedef struct s_var5
{
	int					mi;
	int					mj;
	int					color;
	int					py;
	int					px;
	char				c;
}						t_var5;

typedef struct s_var6
{
	int					j;
	int					s;
	int					len;
	int					idx;
	int					flag;
}						t_var6;

char					*found_the_parse_value(char *line);
char					**my_split(char *input);
int						parse_map(t_map *map, int fd);
int						validate_map(t_map *map);
int						skip_name_color(char *line);
int						find_color_and_parse_them(t_map *map, char *line,
							char c);
// int		check_diagonal(t_map *map , int *befor);
int						remove_new_line(char *line);
int						set_texture_if_match(t_map *map, char *line, int i);
int						set_color_if_match(t_map *map, char *line, int i);
int						drain_after_map(int fd);
int						process_map_row(t_map *map, char *line, int *capacity,
							int *row);
int						process_file_lines(t_map *map, int fd, int *capacity,
							int *row);
void					allocate_map(t_map *map, t_var1 variable, int *row,
							int *capacity);
int						initialization_map(t_map *map, int fd, char *av);
int						parse_split(t_map *map, int *capacity, int *row,
							t_var *variable);
#endif