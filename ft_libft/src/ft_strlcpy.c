/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:04:27 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/04 14:00:42 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return ((size_t)ft_strlen((char *)src));
}

/*
int	main(int ac, char **av)
{
	char 		*s1 = av[1];
	char		s2[20];
	size_t		retorno;

	retorno = strlcpy(s2, s1, (size_t)ft_strlen(s1) - 1);

	printf ("original: %s\n", s1);
	printf ("copia: %s \nretorno: %d\n", s2, retorno);

	return (0);
}
*/
