/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:17:25 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/24 14:05:01 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*
int     main(void)
{
        char    str[] = "Hola aqui";
        char    c = '\0';

        printf ("%s\n", ft_strrchr(str, c));
        printf ("%s\n", s t r r c h r(str, c));
        return (0);
}
*/
