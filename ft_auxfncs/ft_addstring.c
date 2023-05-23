/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:03:41 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/22 20:15:56 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_addstring(t_list **s_clst, va_list params)
{
	char	*value;
	int		control;

	control = 1;
	value = va_arg(params, char*);
	while (control && *value)
	{
		control = ft_addchar(s_clst, value);
		value++;
	}
	if (control)
		control ++;
	return (control);
}
