/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:39:27 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/13 04:35:58 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
// #include <stdio.h>
// int main()
// {
//     int *num = malloc(sizeof(int));
//     *num = 42;
//     t_list *node = ft_lstnew(num);
//     printf("Node content: %d\n", *(int *)(node->content));
//     // Free allocated memory
//     free(num);
//     free(node);
//     return (0);
// }
