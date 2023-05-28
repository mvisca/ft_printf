#include "../ft_printf.h"

int ft_putchar(va_list params, int *i)
{
	int     control;
	int		value;
	char	c;

	value = va_arg(params, int);
	c = (char) value;
	control = write (1, &c, 1);
	*i = *i + 1;
	return (control);
}