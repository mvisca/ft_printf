#include "ft_printf.h"

int	main(void)
{
	int		ret;
	char	c;
	char	str[] = "holA munDo!";

	c = 'A';

	ft_printf("\n == TEST FT single char ==\n");
	ret = ft_printf("%c", c);
	printf("\nRET DEL MAIN: %d\n", ret);
	
	ft_printf("\n == TEST FT %%%% ==\n");
	ret = ft_printf("%%");
	printf("\nRET DEL MAIN: %d\n", ret);
	
	ft_printf("\n == TEST FT %%s ==\n");
	ret = ft_printf("%s", str);
	printf("\nRET DEL MAIN: %d\n", ret);

	ft_printf("\n == TEST FT %%s NULL ==\n");
	ret = ft_printf("NULL %s NULL", NULL);
	printf("\nRET DEL MAIN: %d\n", ret);

	ft_printf("\n == TEST ORI %%p ==\n");
	ret = printf("or-%p", &str);
	printf("\nRET DEL MAIN: %d\n", ret);

	ft_printf("\n == TEST FT %%p ==\n");
	ret = ft_printf("ft-%p", &str);
	printf("\nRET DEL MAIN: %d\n", ret);

	ft_printf("\n == TEST FT %%x ==\n");
	ret = ft_printf("%x", 8376473);
	printf("\nRET DEL MAIN: %d\n", ret);
	
	ft_printf("\n == TEST FT %%X ==\n");
	ret = ft_printf("%X", -8376473);  // negnum
	printf("\nRET DEL MAIN: %d\n", ret);
	
	ft_printf("\n == TEST CORNER FT %%%%x ==\n");
	ret = ft_printf("%%x");
	printf("\nRET DEL MAIN: %d\n", ret);

	ft_printf("\n == TEST CORNER FT %%%%X ==\n");
	ret = ft_printf("%%X");
	printf("\nRET DEL MAIN: %d\n", ret);

	return (0);
}
