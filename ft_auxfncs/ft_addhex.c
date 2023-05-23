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

static void	ft_ulltoha(unsigned long long value, char **aux_ptr, char *base) 
{
	int	i;

	i = 0;
	while (value / 16 > 0)
	{
		(*aux_ptr)[i++] = base[value % 16];
		value = value / 16;
	}
	(*aux_ptr)[i++] = base[value % 16];
	(*aux_ptr)[i++] = base[16];
	(*aux_ptr)[i++] = '0';
	(*aux_ptr)[i] = '\0';
}

int	ft_addhex(t_list **s_clst, va_list params, char x)
{
	unsigned long long	value;
	char				**aux_ptr;
	char				*aux;
	int					control;
	int					len;

	value = va_arg(params, unsigned long long);
	aux = ft_calloc(sizeof(char), 19);
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
	if (control)
		control++;
	return (control);
}
