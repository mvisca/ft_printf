/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:04:28 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/24 14:08:08 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write (fd, &c, 1);
}

/*
CHK!
static int	  prep(char *s)
{
	int	 fd;

	fd = open ("../textfile.txt", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		return (1);
	}
	ft_putnbr_fd(a t o i(s), fd);
	close(fd);
	return (0);
}

int	 main(int ac, char **av)
{
	prep(av[1]);
	system("cat -e ../textfile.txt");
	system("rm ../textfile.txt");
	return (0);
}*/
