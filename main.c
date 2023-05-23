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
	printf("\nRET DEL MAIN: %d\n", ret);

	ret = ft_printf("NULL %s NULL", NULL);
	printf("\nRET DEL MAIN: %d\n", ret);

	ret = printf("or-%p", &str);
	printf("\nRET DEL MAIN: %d\n", ret);

	ret = ft_printf("ft-%p", &str);
	printf("\nRET DEL MAIN: %d\n", ret);

	ret = ft_printf("%x", 31);
	printf("\nRET DEL MAIN: %d\n", ret);
	
	ret = ft_printf("%X", 31);
	printf("\nRET DEL MAIN: %d\n", ret);
	return (0);
}
