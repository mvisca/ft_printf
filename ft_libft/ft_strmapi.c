/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:28:45 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/04 14:16:18 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen((char *) s);
	res = (char *) malloc (sizeof(char) * (len + 1));
	if (res)
	{
		while (s[i])
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
/*
static char	aux_func(unsigned int i, char c)
{
	if (ft_isalpha(c))
		return ('x');
	if (c == ' ')
		return ('_');
	return (c);
}

int	main(int ac, char **av)
{
	char 	s[30] = "Hola 1234 ABCD 1234";
	char	*res;

	res = ft_strmapi(av[1], &aux_func);
	printf ("%s", res);
	return (0);
}
*/
