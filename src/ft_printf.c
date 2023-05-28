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
	else if ((format[*i] == '%') && (format[(*i) + 1] == 's'))
		control = ft_putstr(params, i);
	else if ((format[*i] == '%') && (format[(*i) + 1] == 'd'))
		control = ft_putint(params, i);
	else if ((format[*i] == '%') && (format[(*i) + 1] == 'i'))
		control = ft_putint(params, i);
/*	else if ((format[*i] == '%') && (format[(*i) + 1] == 'u'))
		control = ft_addunsint(s_clst_ptr, params); */
	else if ((format[*i] == '%') && (format[(*i) + 1] == 'p'))
		control = ft_putptr(params, i, 'p');
	else if ((format[*i] == '%') && (format[(*i) + 1] == 'x'))
		control = ft_puthex(params, i, 'x');
	else if ((format[*i] == '%') && (format[(*i) + 1] == 'X'))
		control = ft_puthex(params, i, 'X');
	return (control);
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		control;
	int		printed;
	va_list	params;

	index = 0;
	control = 1;
	printed = 0;
	va_start(params, format);
	while (control != -1 && format[index])
	{
		control = ft_process(params, format, &index);
		if (control == -1)
			return (-1);
		index++;
		printed += control;
	}
	va_end(params);
	if (control == -1)
		return (control);
	return (printed);
}
