/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:03:41 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/23 19:35:56 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_addstring(t_list **s_clst, va_list params)
{
	char	*value;
	char	*aux;
	int		control;

	
	control = 1;
	value = va_arg(params, char*);
	if (!value)
	{
		value = ft_strdup("(null)");
		if (!value)
			return (0);
		aux = value;
		while (control && *aux)
			control = ft_addchar(s_clst, aux++);
		free(value);
	}
	else
	{
		while (control && *value)
			control = ft_addchar(s_clst, value++);
	}
	if (control)
		control ++;
	return (control);
}
