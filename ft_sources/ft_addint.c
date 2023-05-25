#include "../ft_printf.h"

int	ft_addint(t_list **s_clst, va_list params)
{
	int		value;
	int		control;
	int		i;
	char	*num;
	
	control = 1;
	i = 0;
	value = va_arg(params, int);
	num = ft_itoa(value);
	if (!num)
		return (0);
	while (control && num[i])
		control = ft_addchar(s_clst, &num[i++]);
	if (control)
		control++;
	free(num);
	return (control);
}
