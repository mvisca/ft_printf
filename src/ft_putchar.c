/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:41:16 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/29 19:31:29 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(va_list params, int *i)
{
	int		control;
	int		value;
	char	c;

	value = va_arg(params, int);
	c = (char) value;
	control = write (1, &c, 1);
	*i = *i + 1;
	return (control);
}
