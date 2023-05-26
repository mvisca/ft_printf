/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:55:23 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/26 18:55:30 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	res;
	int				i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = (res * 10) + (nptr[i++] - '0');
	return (res * sign);
}

/*
int	main(int ac, char **av)
{
	char *s = "  \v\r\f\n\t ia+22";
	if (ac == 2)
	{
		printf ("MIO=%d\n", ft_atoi(av[1]));
		printf ("ORI=%d\n", a t o i(av[1]));
	}
	else
	{
		printf ("MIO=%d\n", ft_atoi(s));
		printf ("ORI=%d\n", a t o i(s));
	}
	return (0);
}
*/
