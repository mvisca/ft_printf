/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:24:15 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/03 17:28:26 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/*
Chk
static int	  prep(char *s)
{
		int	 	fd;
		char	buff[1];
		int		bread;

		fd = open ("../textfile.txt", O_WRONLY | O_CREAT, 0644);
		if (fd < 0)
		{
				return (1);
		}
		while ((bread = read(fd, buff, 1)) > 0)
				;
		ft_putstr_fd(s, fd);
		close(fd);
		return (0);
}

int	 main(int ac, char **av)
{
		prep(av[1]);
		return (0);
}
*/
