#include "ft_printf.h"

// Definición de constantes de color
#define NC		"\x1B[0m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define MAGENTA	"\x1B[35m"
#define CYAN	"\x1B[36m"

int	main(void)
{
	int		ret;
	char	c = 'A';
//	char	str[] = "holA munDo!";
//	char	*strptr = NULL;

// FORMAT
	ft_printf(BLUE"\n == TEST format ==\n"NC);
	ret = ft_printf("FT: This is a format sourced string");
	printf("\nRet: %d\n", ret);
	ret = printf("OR: This is a format sourced string");
	printf("\nRet: %d\n", ret);
	
// CHAR
	ft_printf(RED"\n == TEST '%%c' ==\n"NC);
	ret = ft_printf("FT: %c", c);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %c", c);
	printf("\nRet: %d\n", ret);

// %%
	ft_printf(BLUE"\n == TEST '%%%%' ==\n"NC);
	ret = ft_printf("FT: %%");
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %%");
	printf("\nRet: %d\n", ret);

	return (0);
}
