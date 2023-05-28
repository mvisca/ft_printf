#include "../ft_printf.h"

int ft_putstr(va_list params, int *i)
{
	int     control;
	char    *value;

	value = va_arg(params, char *);
	if (value)
    	control = write (1, value, ft_strlen(value));
	else
		control = write(1, "(null)", 6);
	*i = *i + 1;
	return (control);
}