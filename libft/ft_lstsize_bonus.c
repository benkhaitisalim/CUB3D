/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 03:46:50 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/13 04:47:30 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*lsttmp;
	int		count;

	lsttmp = lst;
	count = 0;
	while (lsttmp)
	{
		lsttmp = lsttmp->next;
		count++;
	}
	return (count);
}
// #include <stdio.h>
// int main()
// {
//     t_list *head = ft_lstnew("Salim");
//     t_list *second = ft_lstnew("said");
//     t_list *third = ft_lstnew("jalal");
//     // Link the nodes
//     head->next = second;
//     second->next = third;
//     // Use ft_lstlast to get the last node
//    int last_node = ft_lstsize(head);
//     if (last_node) {
//         printf("Last node content: %d\n", last_node);
//     } else {
//         printf("The list is empty.\n");
//     }
// 	return(0);
// }