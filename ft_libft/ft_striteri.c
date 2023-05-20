/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:13:40 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/06 20:58:36 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
static void	aux_func(unsigned int i, char *s)
{
	if (ft_isalpha(s[i]))
		s[i] = 'x';
	if (s[i] == ' ')
		s[i] = '_';
}

int	 main(int ac, char **av)
{
	char	s[30] = "Hola 1234 ABCD 1234";
	char	*res;

	ft_striteri(av[1], &aux_func);
	printf ("%s", av[1]);
	return (0);
}
*/
