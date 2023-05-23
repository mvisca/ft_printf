#include "ft_printf.h"

int	main(void)
{
	int		ret;
	char	c;
	char	str[] = "holA munDo!";

	c = 'A';
	ret = ft_printf("Test char 'A' = > &c <!\n", c);
	printf("RET DEL MAIN: %d\n", ret);
	ret = ft_printf("Test doble percent > '%%' <\n", c);
	printf("RET DEL MAIN: %d\n", ret);
	ret = ft_printf("Test string 'holA munDo!' > %s <\n", str);
	printf("RET DEL MAIN: %c\n", c);
	return (0);
}
