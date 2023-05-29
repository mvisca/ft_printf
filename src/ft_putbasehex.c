#include "../ft_printf.h"

static int	ft_process_ultoa(unsigned long value, char *base)
{
	int				control;
	int				len;
	unsigned long	temp;
	char			*num;

	num = ft_calloc(sizeof(char), 25);
	if (!num)
		return (-1);
	len = 1;
	temp = value;
	while (temp / 16)
	{
		temp /= 16;
		len++;
	}
	while (value / 16)
	{
		num[len - 1] = base[value % 16];
		value /= 16;
		len--;
	}
	num[len - 1] = base[value % 16];
	control = write (1, num, ft_strlen(num));
	free(num);
	return (control);
}

static int ft_ultoa(unsigned long value, char mode)
{
	int		control;
	int		printed;

	printed = 0;
	if (mode == 'p')
	{
		control = write (1, "0x", 2);	
		if (control == -1)
			return (control);
		printed += control;
	}
	if (mode == 'p' || mode == 'x')
		control = ft_process_ultoa(value, "0123456789abcdef");
	else
		control = ft_process_ultoa(value, "0123456789ABCDEF");
	if (control == -1)
		return (control);
	printed += control;
	return (printed);
}

int ft_putptr(va_list params, int *i, char mode)
{
	int		control;
	void	*value;

	*i = *i + 1;
	value = va_arg(params, void *);
	control = ft_ultoa((unsigned long)value, mode);
	return (control);
}

int ft_puthex(va_list params, int *i, char mode)
{
	int				control;
	unsigned int	value;
	
	*i = *i + 1;
	value = va_arg(params, unsigned int);
	control = ft_ultoa((unsigned long)value, mode);
	return (control);
}