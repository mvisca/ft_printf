/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:09:51 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/26 21:44:31 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strprint(char *str)
{
	int	printed;

	printed = write(1, str, ft_strlen(str));
	if (printed == -1)
		return (0);
	return (printed);
}

static int	ft_lstprint(t_list **s_clst_ptr)
{
	int		i;
	int		j;
	int		printed;
	int		control;
	char	str[1024];
	t_list	*s_temp;

	i = 0;
	printed= 0;
	control = 1;
	s_temp = *s_clst_ptr;
	while (s_temp && control)
	{
		j = 0;
		while (((char *)s_temp->content)[i])
			str[i++] = (char *)s_temp->content[j++];
		if (i > 1022 || !s_temp->next)
		{
			control = ft_strprint(str);
			if (!control)
				return (-1);
			printed += control;
		}
		s_temp = s_temp->next;
	}
	return (printed);
}

static int	ft_process(const char *format, va_list params, t_list **s_clst_ptr)
{
	int	control;

	if (*format != '%')
		control = ft_addchar(s_clst_ptr, format);
	else if (*format == '%' && *(format + 1) == '%')
		control = ft_addchar(s_clst_ptr, ++format);
	else if (*format == '%' && *(format + 1) == 'c')
		control = ft_addcharva(s_clst_ptr, params);
	else if (*format == '%' && *(format + 1) == 's')
		control = ft_addstring(s_clst_ptr, params);
	else if (*format == '%' && *(format + 1) == 'd')
		control = ft_addint(s_clst_ptr, params);
	else if (*format == '%' && *(format + 1) == 'i')
		control = ft_addint(s_clst_ptr, params);
	else if (*format == '%' && *(format + 1) == 'u')
		control = ft_addunsint(s_clst_ptr, params);
	else if (*format == '%' && *(format + 1) == 'p')
		control = ft_addhex(s_clst_ptr, params, 'x');
	else if (*format == '%' && *(format + 1) == 'x')
		control = ft_addhexnum(s_clst_ptr, params, 'x');
	else if (*format == '%' && *(format + 1) == 'X')
		control = ft_addhexnum(s_clst_ptr, params, 'X');
	else
		control = 0;
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
	control = 1;
	printed = -1;
	va_start(params, format);
	while (control && *format)
	{
		control = ft_process(format, params, s_clst_ptr);
		format += control;
	}
	va_end(params);
	if (control)
		printed = ft_lstprint(s_clst_ptr);
	ft_lstclear(s_clst_ptr, ft_del);
	return (printed);
}
