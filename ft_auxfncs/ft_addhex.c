/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:55:27 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/23 21:00:49 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_ulltoha(unsigned long long value, char *aux, char *base) 
{
	int		i;
	char	tmp [19];

	i = 17;
	while (value / 16)
	{
		tmp[i] = base[value % 16];
		value = value / 16;
		i--;
	}
	i++;
	while (tmp[i])
	{
		aux[18 - i + 2] = tmp[i];
		i++;
	}
}

int	ft_addhex(t_list **s_clst, va_list params, char x)
{
	unsigned long long	value;
	char				*aux;
	int					control;
	int					i;

	value = va_arg(params, unsigned long long);
	aux = ft_calloc(sizeof(char), 19);
	control = 1;
	i = 0;
	aux[0] = '0';
	if (x == 'x')
	{
		ft_ulltoha(value, aux, "0123456789abcdef\0");
		aux[1] = 'x';
	}
	else
	{
		ft_ulltoha(value, aux, "0123456789ABCDEF\0");
		aux[1] = 'X';
	}
	while (control && aux[i])
		control = ft_addchar(s_clst, &aux[i++]);
	if (control)
		control++;
	return (control);
}
