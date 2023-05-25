#include "../ft_printf.h"

int	ft_addint(t_list **s_clst, va_list params)
{
	int		value;
	int		value_copy;
	int		len;
	int		control;
	char	*num;
	
	control = 0;
	value = va_arg(params, int);
	value_copy = value;
	len = 0;
	while (value_copy / 10)
		len++;
	num = ft_strdup(ft_itoa(value));
	control = ft_addchar(s_clst, num);
	if (control)
		control++;
	return (control);
}
