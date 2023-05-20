/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:52:02 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/04 14:22:17 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*
Checked
static int	prep(char *s)
{
	int	fd;

	fd = open ("../textfile.txt", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		return (1);
	}
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	prep(av[1]);
	return (0);
}
*/
