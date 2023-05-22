/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:09:51 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/22 17:00:09 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// c s p d i(0, 0b, 0x) u x X %

// todas las funciones reciben el puntero en el char previo al que deben procesar
	// addchar() adds a char to s_clst
	// addint() takes char as param, d for int and i to check format
	// addstring() adds string
	// addhex() adds lowercase hex
	// addhexupper() adds uppercase hex
	// addunsint() adds uninsgend int

static int	ft_lstprint(t_list *s_clst)
{
	int		printed;
	char	c;
	t_list	*s_temp;

	printed = 0;
	s_temp = s_clst;
	write (1, "->", 2);
	while (s_temp)
	{
		c = *(char *)(s_temp->content);
		write (1, &c, 1);
		s_temp = s_temp->next;
		printed++;
	}
	printf("printed in func == %d\n", printed);
	return (printed);
}

static int	ft_process(const char *format, va_list params, t_list **s_clst)
{
	int control;
	int	c;

	c = va_arg(params, int);
	printf("para que compile %% %d\n", c);
	control = 1;
	while (control && *format)
	{
		if (*format != '%')
			control = ft_addchar(s_clst, format);
		else if (*format == '%' && *(format + 1) == '%')
			control = ft_addchar(s_clst, ++format);
		else if (*format == '%' && *(format + 1) == 'c')
			control = ft_addcharva(s_clst, params, ++format);
/*
		else if (*format == '%' && *(format + 1) == 's')
			control = ft_addstring(s_clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'p')
			control = ft_addhex(s_clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'd')
			control = ft_addint(s_clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'i')
			control = ft_addnum(s_clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'u')
			control = ft_addunsint(s_clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'x')
			control = ft_addhex(s_clst, params, ++format);
		else if (*format == '%' && *(format + 1) == 'X')
			control = ft_addhexupper(s_clst, params, ++format);
*/
		else
			control = 0;
		format++;
	}
	c = ft_lstprint(*s_clst);
	printf("\nSALIDA DE PROCESSS %d\n", c);
	return (control);
}

int	ft_printf(const char *format, ...)
{
	va_list	params; // params
	t_list	**s_clst_ptr; // head of the linked list of chars
	t_list	*s_clst;
	int		control;
	int		printed; // count of the chars printed
	
	va_start(params, format);
	s_clst = NULL;
	printed = 0;
	s_clst_ptr = &s_clst;
	control = ft_process(format, params, s_clst_ptr);
	va_end(params);
	printf("control  == %d\n", control);
	if (control > 0)
		printed = ft_lstprint(*s_clst_ptr);
	printf("PRINTED %d\n", printed); 
	ft_lstclear(s_clst_ptr, ft_del);
	s_clst = NULL;
	return (printed);
}
