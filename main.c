#include "ft_printf.h"

int	main(void)
{
	int		ret;
	char	c;
	char	str[] = "holA munDo!";

	c = 'A';

	ret = ft_printf("%c", c);
	printf("\nRET DEL MAIN: %d\n", ret);
	
	ret = ft_printf("%%");
	printf("\nRET DEL MAIN: %d\n", ret);
	
	ret = ft_printf("%s", str);
	printf("\nRET DEL MAIN: %c\n", c);
	
	return (0);
}
