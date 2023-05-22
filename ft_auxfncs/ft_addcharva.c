/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addcharva.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:10:23 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/22 16:59:59 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_addcharva(t_list **s_clst, va_list params, const char *format)
{
	int	c;
	int	control;

	c = va_arg(params, int);
	printf("esto desde addcharva> %c\n", c);
	control = ft_addchar(s_clst, format);
	return (control);
}
