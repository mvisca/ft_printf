#include "../ft_printf.h"

int	ft_putformat(const char *format, int *i)
{
	int ret;

	ret = write (1, &format[*i], 1);
	(*i)++;
	return (ret);
}