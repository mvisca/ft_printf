#include "ft_printf.h"

//static int	ft_process(const char *format, int *i, va_list params)
static int	ft_process(const char *format, int *i)
{
	int	control;

	if (format[(*i)] != '%')
		control = ft_putformat(format, i);

	else if ((format[*i] == '%') && (format[(*i)] == '%'))
		control = ft_putformat(format, i);
/*	
	else if (*format == '%' && *(format + 1) == 'c')
		control = ft_putchar(s_clst_ptr, params);
	
	else if (*format == '%' && *(format + 1) == 's')
		control = ft_addstring(s_clst_ptr, params);
	
	else if (*format == '%' && *(format + 1) == 'd')
		control = ft_addint(s_clst_ptr, params);
	
	else if (*format == '%' && *(format + 1) == 'i')
		control = ft_addint(s_clst_ptr, params);
	
	else if (*format == '%' && *(format + 1) == 'u')
		control = ft_addunsint(s_clst_ptr, params);
	
	else if (*format == '%' && *(format + 1) == 'p')
		control = ft_addptr(s_clst_ptr, params, 'x');
	
	else if (*format == '%' && *(format + 1) == 'x')
		control = ft_addhexnum(s_clst_ptr, params, 'x');
	
	else if (*format == '%' && *(format + 1) == 'X')
		control = ft_addhexnum(s_clst_ptr, params, 'X');
*/	
	else
		control = -1;
	return (control);
}

int	ft_printf(const char *format, ...)
{
	int		control;
	int		printed;
	int		index;
	int		*i;
	va_list	params;

	control = 1;
	printed = 0;
	index = 0;
	i = &index;
	va_start(params, format);
	while (control && format[*i])
	{
//		control = ft_process(format, i, params);
		control = ft_process(format, i);
		if (control == -1)
			return (-1);
		printed += control;
	}
	va_end(params);
	return (printed);
}
