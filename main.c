#include "libftprintf.h"

int	main(void)
{
	int	ret;

	ret = ft_printf("Hola%%Mundo!");
	printf("RET DEL MAIN: %d\n", ret);
	return (0);
}
