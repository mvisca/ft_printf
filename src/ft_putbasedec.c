#include "../ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	int				len;
	long int		ncpy;
	char			*res;

	len = 0;
	ncpy = n;
	while (ncpy)
	{
		ncpy /= 10;
		len++;
	}
	res = malloc ((len) * sizeof(char));
	if (!res)
		return (NULL);
	while (len--)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}

int	ft_putunsint(va_list params, int *i)
{
	int				control;
	unsigned int	value;
	char			*num;

	value = va_arg(params, unsigned int);
	if (value == 0)
	{
		num = ft_strdup("0");
		if (!num)
			return (NULL);
		return (num);
	} 
	num = ft_utoa(value);
	if (!num)
		return (-1);
	control = write (1, num, ft_strlen(num));
	if (control == -1)
	{
		free(num);
		return (-1);
	}
	*i = *i + 1;
	free(num);
	return (control);
}

int ft_putint(va_list params, int *i)
{
	int     control;
	int		value;
	char	*num;

	value = va_arg(params, int);
	num = ft_itoa(value);
	if (!num)
		return (-1);
	control = write (1, num, ft_strlen(num));
	*i = *i + 1;
	free(num);
	return (control);
}