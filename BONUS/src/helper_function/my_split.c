/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:19:17 by bsalim            #+#    #+#             */
/*   Updated: 2025/10/31 22:50:21 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "../parse.h"

int	count_word(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (input[i])
		{
			count++;
			while (input[i] && !ft_isspace(input[i]))
				i++;
		}
	}
	return (count);
}

void	init_var_split(t_var4 *var, char *input)
{
	var->words = count_word(input);
	var->tmp = malloc(sizeof(char *) * (var->words + 1));
	var->word = 0;
	if (!var->tmp)
		return ;
	var->i = 0;
}

void	find_size_word(char *input, t_var4 *var)
{
	var->index = 0;
	while (input[var->i + var->index]
		&& !ft_isspace(input[var->i + var->index]))
		var->index++;
	var->tmp[var->word] = malloc(sizeof(char) * (var->index + 1));
	if (!var->tmp)
	{
		free_double_arr(var->tmp);
		return ;
	}
}

char	**my_split(char *input)
{
	t_var4	var;

	init_var_split(&var, input);
	while (input[var.i])
	{
		while (input[var.i] && ft_isspace(input[var.i]))
			var.i++;
		if (input[var.i])
		{
			find_size_word(input, &var);
			var.fill = 0;
			while (var.fill < var.index)
			{
				var.tmp[var.word][var.fill] = input[var.i + var.fill];
				var.fill++;
			}
			var.tmp[var.word][var.fill] = '\0';
			var.word++;
			var.i += var.index;
		}
	}
	var.tmp[var.word] = NULL;
	return (var.tmp);
}
