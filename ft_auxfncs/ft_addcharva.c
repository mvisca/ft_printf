/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addcharva.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:10:23 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/22 20:13:46 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_addcharva(t_list **s_clst, va_list params)
{
	int		value;
	char	c[2];
	int 	control;

	control = 0;
	value = va_arg(params, int);
	c[0] = value;
	c[1] = '\0';
	printf("esto desde addcharva> >> %d <<\n", value);
	control = ft_addchar(s_clst, c);
	if (control)
		control++;
	return (control);
}
