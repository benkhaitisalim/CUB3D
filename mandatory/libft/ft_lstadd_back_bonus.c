/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 03:58:34 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/31 04:06:51 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *ne)
{
	t_list	*newnback;

	if (*lst == NULL)
	{
		*lst = ne;
		return ;
	}
	newnback = ft_lstlast(*lst);
	newnback->next = ne;
}
