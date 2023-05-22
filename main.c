#include "ft_printf.h"

int	main(void)
{
	int		ret;
	char	c;

	c = 'A';
	ret = ft_printf("Hola%%Mundo %c !\n", c);
	printf("RET DEL MAIN: %d\n", ret);
	return (0);
}
