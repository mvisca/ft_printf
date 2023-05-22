/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:34:30 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/04 14:21:00 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
Ck!
static int	  prep(char *s)
{
	int	 fd;

	fd = open ("../textfile.txt", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		return (1);
	}
//	while (*s)
//	{
		ft_putendl_fd(s, fd);
//		s++;
//	}
	close(fd);
	return (0);
}

int	 main(int ac, char **av)
{
	prep(av[1]);
	system("cat -e ../textfile.txt");
	system("rm ../textfile.txt");
	return (0);
}
*/
