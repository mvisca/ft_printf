#include "ft_printf.h"

int	ft_addint(t_list **s_clst, va_list params)
{
	int		value;
	int		control;
	char	*num;
	
	control = 0;
	value = va_arg(params, int);
	num = ft_itoa(value);
	if (!num)
		return (0);
	control = ft_addchar(s_clst, num);
	if (control)
		control++;
	return (control);
}
