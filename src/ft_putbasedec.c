#include "../ft_printf.h"

int ft_putint(va_list params, int *i)
{
	int     control;
	int		value;
	char	*num;

	value = va_arg(params, int);
	num = ft_itoa(value);
	control = write (1, num, ft_strlen(num));
	*i = *i + 1;
	free(num);
	return (control);
}