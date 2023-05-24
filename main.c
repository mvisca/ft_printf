#include "ft_printf.h"

int	main(void)
{
	int		ret;
	char	c = 'A';
	char	str[] = "holA munDo!";
	char		*strptr = NULL;

	ft_printf("\n == TEST '%%c' ==\n");
	ret = ft_printf("FT: %c", c);
	printf("\nRET: %d\n", ret);
	ret = printf("OR: %c", c);
	printf("\nRET: %d\n", ret);
	
	ft_printf("\n == TEST '%%%%' ==\n");
	ret = ft_printf("FT: %%");
	printf("\nRET: %d\n", ret);
	ret = printf("OR: %%");
	printf("\nRET: %d\n", ret);
	
	ft_printf("\n == TEST '%%s' ==\n");
	ret = ft_printf("FT: %s", str);
	printf("\nRET: %d\n", ret);
	ret = printf("OR: %s", str);
	printf("\nRET: %d\n", ret);

	ft_printf("\n == TEST '%%s NULL' ==\n");
	ret = ft_printf("FT: NULL %s NULL", NULL);
	printf("\nRET: %d\n", ret);
	ret = printf("OR: NULL %s NULL", strptr);
	printf("\nRET: %d\n", ret);

	ft_printf("\n == TEST '%%p' ==\n");
	ret = ft_printf("FT: %p", &str);
	printf("\nRET: %d\n", ret);
	ret = printf("OR: %p", &str);
	printf("\nRET: %d\n", ret);

	ft_printf("\n == TEST '%%x' > 0 ==\n");
	ret = ft_printf("FT: %x", 3456);
	printf("\nRET: %d\n", ret);
	ret = printf("OR: %x", 3456);
	printf("\nRET: %d\n", ret);

	ft_printf("\n == TEST '%%X' > 0 ==\n");
	ret = ft_printf("FT: %p", 3456);
	printf("\nRET: %d\n", ret);
	ret = printf("OR: %X", 3456); 
	printf("\nRET: %d\n", ret);

	ft_printf("\n == TEST '%%x' < 0 ==\n");
	ret = ft_printf("FT: %x", -3456);
	printf("\nRET: %d\n", ret);
	ret = printf("OR: %x", -3456);
	printf("\nRET: %d\n", ret);
	
	ft_printf("\n == TEST '%%X' < 0 ==\n");
	ret = ft_printf("FT: %X", -3456);  // negnum
	printf("\nRET: %d\n", ret);
	ret = printf("OR: %X", -3456);  // negnum
	printf("\nRET: %d\n", ret);
	
	ft_printf("\n == TEST '%%X' < 0 ==\n");
	ret = ft_printf("FT: %X", -3456);  // negnum
	printf("\nRET: %d\n", ret);
	ret = printf("OR: %X", -3456);  // negnum
	printf("\nRET: %d\n", ret);
	
	ft_printf("\n == TEST CORNER FT %%%%x ==\n");
	ret = ft_printf("%%x");
	printf("\nRET DEL MAIN: %d\n", ret);

	ft_printf("\n == TEST CORNER FT %%%%X ==\n");
	ret = ft_printf("%%X");
	printf("\nRET DEL MAIN: %d\n", ret);

	return (0);
}
