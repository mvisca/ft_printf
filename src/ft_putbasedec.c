/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbasedec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:15:28 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/06/01 14:21:25 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	int				len;
	unsigned long	ncpy;
	char			*res;

	if (!n)
		res = ft_strdup("0");
	else
	{
		len = 0;
		ncpy = n;
		while (ncpy)
		{
			ncpy /= 10;
			len++;
		}
		res = ft_calloc (len + 1, sizeof(char));
		if (!res)
			return (NULL);
		while (len--)
		{
			res[len] = n % 10 + '0';
			n = n / 10;
		}
	}
	return (res);
}

int	ft_putunsint(va_list params, int *i)
{
	int				control;
	unsigned int	value;
	char			*num;

	value = va_arg(params, unsigned int);
	num = ft_utoa(value);
	if (!num)
		return (-1);
	control = write (1, num, ft_strlen(num));
	(*i)++;
	free(num);
	return (control);
}

int	ft_putint(va_list params, int *i)
{
	int		control;
	int		value;
	char	*num;

	value = va_arg(params, int);
	num = ft_itoa(value);
	if (!num)
		return (-1);
	control = write (1, num, ft_strlen(num));
	(*i)++;
	free(num);
	return (control);
}
