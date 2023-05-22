/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:10:01 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/03 20:41:24 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static char	*ft_makeitoa(int ncpy, char *tmp)
{
	while (ncpy / 10 > 0)
	{
		ft_memmove((tmp + 1), tmp, ft_strlen(tmp));
		tmp[0] = ncpy % 10 + '0';
		ncpy = ncpy / 10;
	}
	ft_memmove((tmp + 1), tmp, ft_strlen(tmp));
	tmp[0] = ncpy + '0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	char	*res;
	int		ncpy;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ncpy = ft_abs(n);
	tmp = (char *) ft_calloc (13, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	ft_makeitoa(ncpy, tmp);
	if (n < 0)
	{
		ft_memmove(&tmp[1], tmp, ft_strlen(tmp));
		tmp[0] = '-';
	}
	res = ft_strdup(tmp);
	free(tmp);
	return (res);
}

/*
int	main(int ac, char **av)
{
	char *res;

	res = ft_itoa(atoi(av[1]));
	printf ("Num=%s", res);

	return (0);
}
*/
