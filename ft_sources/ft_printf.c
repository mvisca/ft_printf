/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:09:51 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/24 19:54:47 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// c s p d i(0, 0b, 0x) u x X %

static int	ft_lstprint(t_list **s_clst_ptr)
{
	int		printed;
	char	c;
	t_list	*s_temp;

	printed = 0;
	s_temp = *s_clst_ptr;
	while (s_temp)
	{
		c = *(char *)(s_temp->content);
		if (write (1, &c, 1) == -1)
		{
			ft_lstclear(s_clst_ptr, ft_del);
			return (-1);
		}
		s_temp = s_temp->next;
		printed++;
	}
	return (printed);
}

static int	ft_process(const char *format, va_list params, t_list **s_clst_ptr)
{
	int	control;

	control = 1;
	while (control && *format)
	{
		if (*format != '%')
			control = ft_addchar(s_clst_ptr, format);
		else if (*format == '%' && *(format + 1) == '%')
			control = ft_addchar(s_clst_ptr, ++format);
//		else if (*format == '%' && *(format + 1) == 'c')
//			control = ft_addcharva(s_clst_ptr, params);
		else if (*format == '%' && *(format + 1) == 's')
			control = ft_addstring(s_clst_ptr, params);
		else if (*format == '%' && *(format + 1) == 'd')
			control = ft_addint(s_clst_ptr, params);
		else if (*format == '%' && *(format + 1) == 'u')
			control = ft_addunsint(s_clst_ptr, params);
		else if (*format == '%' && *(format + 1) == 'i')
			control = ft_addunsint(s_clst_ptr, params);
		else if (*format == '%' && *(format + 1) == 'p')
			control = ft_addhex(s_clst_ptr, params, 'x');
		else if (*format == '%' && *(format + 1) == 'x')
			control = ft_addhexnum(s_clst_ptr, params, 'x');
		else if (*format == '%' && *(format + 1) == 'X')
			control = ft_addhexnum(s_clst_ptr, params, 'X');
		else
			control = 0;
		format += control;
	}
	return (control);
}

int	ft_printf(const char *format, ...)
{
	t_list	*s_clst;
	t_list	**s_clst_ptr;
	int		control;
	int		printed;
	va_list	params;

	s_clst = NULL;
	s_clst_ptr = &s_clst;
	printed = 0;
	va_start(params, format);
	control = ft_process(format, params, s_clst_ptr);
	va_end(params);
	if (control > 0)
		printed = ft_lstprint(s_clst_ptr);
	ft_lstclear(s_clst_ptr, ft_del);
	s_clst = NULL;
	return (printed);
}
