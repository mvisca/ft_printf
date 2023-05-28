#include "../ft_printf.h"

static int	ft_process(va_list params, const char *format, int *i)
{
	int	control;

	if (format[(*i)] != '%')
		control = write (1, &format[(*i)], 1);
	else if ((format[*i] == '%') && (format[(*i) + 1] == '%'))
		control = write (1, &format[++(*i)], 1);
	else if ((format[*i] == '%') && (format[(*i) + 1] == 'c'))
		control = ft_putchar(params, i);
/*
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
	(*i) = (*i) + control;
	return (control);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		index;
	int		control;
	int		printed;

	va_start(params, format);
	index = 0;
	control = 1;
	printed = 0;
	while (control && format[index])
	{
		control = ft_process(params, format, &index);
		if (control == -1)
			return (-1);
		printed += control;
	}
	va_end(params);
	return (printed);
}
