/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 03:53:16 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/15 01:54:36 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*thelast;

	if (!lst)
		return (NULL);
	thelast = lst;
	while (thelast->next)
		thelast = thelast->next;
	return (thelast);
}

// #include <stdio.h>
// int main()
// {
//     t_list *head = ft_lstnew("jalal");
//     t_list *second = ft_lstnew("said");
//     t_list *third = ft_lstnew("Salim");
//     // Link the nodes
//     head->next = second;
//     second->next = third;
//     // Use ft_lstlast to get the last node
//    t_list *last_node = ft_lstlast(head);
//     if (last_node) {
//         printf("Last node content: %c\n", *(char *)(last_node->content));
//     } else {
//         printf("The list is empty.\n");
//     }
// 	return(0);
// }