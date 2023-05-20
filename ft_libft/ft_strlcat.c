/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:42:07 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/04 13:58:34 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_src = ft_strlen((char *)src);
	len_dest = ft_strlen(dest);
	if (size == 0)
		return (len_src);
	else if (size < len_dest)
		return (len_src + size);
	else
	{
		len_src += len_dest;
		i = 0;
		while (src[i] && (len_dest + i) < size - 1)
		{
			dest[len_dest + i] = src[i];
			i++;
		}
		dest[len_dest + i] = '\0';
	}
	return (len_src);
}

/*
int	main(int ac, char **av)
{
	char 		*s1 = av[1];
	char		s2[30] = "hola ";
	char		s3[30] = "hola ";
	size_t		retorno;

	system("clear");
	retorno = ft_strlcat(s2, s1, atoi(av[2]));

	printf ("src: %s\n", s1);
	printf ("dest ini: %s\n\n", s2);
	
	printf ("dest ft: %s \nretorno> %lu\n\n", s2, retorno);
	
	retorno = strlcat(s3, s1, atoi(av[2]));
	printf ("dest ori: %s \nretorno> %lu\n", s3, retorno);

	return (0);
}
*/
