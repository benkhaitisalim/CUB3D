/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 05:35:20 by bsalim            #+#    #+#             */
/*   Updated: 2024/11/10 05:43:55 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main() {
//     // Test writing to standard output
//     ft_putchar_fd('A', STDOUT_FILENO);  // Should print 'A' to the console
//     write(STDOUT_FILENO, "\n", 1);       // Newline for clarity
//     ft_putchar_fd('B', fd);  // Should write 'B' to the file
//     close(fd);
//     return (0);  // Return 0 to indicate success
// }