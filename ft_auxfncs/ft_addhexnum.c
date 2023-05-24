/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addhexnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:45:27 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/24 19:54:45 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_ulltoha(long long value, char **aux_ptr, char *base) 
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	if (value < 0)
		neg = 1;
	while (value > 0)
	{
		(*aux_ptr)[i++] = base[value % 16];
		value = value / 16;
	}
	if (neg)
		(*aux_ptr)[i++] = '-';
	(*aux_ptr)[i] = '\0';
}

int	ft_addhexnum(t_list **s_clst, va_list params, char x)
{
	long long	value;
	char		**aux_ptr;
	char		*aux;
	int			control;
	int			len;

	value = va_arg(params, unsigned long long);
	aux = malloc(sizeof(char) * 18);

	if (!aux)
		return (0);
	aux_ptr = &aux;
	control = 1;
	if (x == 'x')
		ft_ulltoha(value, aux_ptr, "0123456789abcdefx\0");
	else
		ft_ulltoha(value, aux_ptr, "0123456789ABCDEFX\0");
	len = ft_strlen(aux);
	while (control && len > 0)
		control = ft_addchar(s_clst, &aux[--len]);
	free(aux);
	if (control)
		control++;
	return (control);
}
