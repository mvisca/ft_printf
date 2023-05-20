/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:51:29 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/06 16:43:28 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{	
	size_t			i;
	unsigned char	*dcpy;
	unsigned char	*scpy;

	dcpy = (unsigned char *)dest;
	scpy = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dcpy[i] = scpy[i];
		i++;
	}
	while (i < n)
		(dcpy)[i++] = '\0';
	return (dcpy);
}

/*
int	main(void)
{
	char	a[30];
	char	b[30];

//	ft_strlcpy(a, "Hola Dani", 10);
	ft_strlcpy(a, ((void *)0), 10);
	ft_strlcpy(b, "xxxx", 10);
//	ft_strlcpy(b, ((void *)0), 10);
	ft_memcpy(a, b, 10);
	printf ("%s", a);
	return (0);
}
*/
