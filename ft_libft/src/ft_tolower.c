/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:38:36 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/03 21:13:47 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((unsigned char) c >= 'A' && (unsigned char) c <= 'Z')
		c += 32;
	return (c);
}

/*
int	main(void)
{
	unsigned char	c;

	c = 'A';
	printf ("%c <> %c", c, ft_tolower(c));
	return (0);
}
*/
