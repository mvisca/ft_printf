#include <ft_printf.h>
#include <libft.h>

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
	char	str[] = "holA munDo!";
	char	*strptr = NULL;

// FORMAT
	ft_printf(BLUE"\n == TEST format ==\n"NC);
	ret = ft_printf("FT: This is a format sourced string");
	printf("\nRet: %d\n", ret);
	ret = printf("OR: This is a format sourced string");
	printf("\nRet: %d\n", ret);
	
// CHAR
	ft_printf(BLUE"\n == TEST '%%c' ==\n"NC);
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

// STRING
	ft_printf(RED"\n == TEST '%%s' ==\n"NC);
	ret = ft_printf("FT: %s", str);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %s", str);
	printf("\nRet: %d\n", ret);

// NULL STRING
	ft_printf(RED"\n == TEST '%%s NULL' ==\n"NC);
	ret = ft_printf("FT: NULL %s NULL", NULL);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: NULL %s NULL", strptr);
	printf("\nRet: %d\n", ret);

// INT
	ft_printf(GREEN"\n == TEST '%%d' < 0 ==\n"NC);
	ret = ft_printf("FT: %d", -3456);  // negnum
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %d", -3456);  // negnum
	printf("\nRet: %d\n", ret);
	
	ft_printf(GREEN"\n == TEST '%%d' > 0 ==\n"NC);
	ret = ft_printf("FT: %d", 3456);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %d", 3456);
	printf("\nRet: %d\n", ret);
	
// INT
	ft_printf(GREEN"\n == TEST '%%i' > 0 ==\n"NC);
	ret = ft_printf("FT: %d", 3456);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %i", 3456);
	printf("\nRet: %d\n", ret);

	ft_printf(GREEN"\n == TEST '%%i' < 0 ==\n"NC);
	ret = ft_printf("FT: %i", -47384);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %i", -47384);
	printf("\nRet: %d\n", ret);

	ft_printf(GREEN"\n == TEST '%%i' == 0 ==\n"NC);
	ret = ft_printf("FT: %i", 0);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %i", 0);
	printf("\nRet: %d\n", ret);

// HEX
	ft_printf(YELLOW"\n == TEST '%%x' > 0 ==\n"NC);
	ret = ft_printf("FT: %x", 3456);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %x", 3456);
	printf("\nRet: %d\n", ret);

	ft_printf(YELLOW"\n == TEST '%%X' > 0 ==\n"NC);
	ret = ft_printf("FT: %X", 3456);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %X", 3456); 
	printf("\nRet: %d\n", ret);

// NEG HEX
	ft_printf(YELLOW"\n == TEST '%%x' < 0 ==\n"NC);
	ret = ft_printf("FT: %x", -3456);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %x", -3456);
	printf("\nRet: %d\n", ret);
	
	ft_printf(YELLOW"\n == TEST '%%X' < 0 ==\n"NC);
	ret = ft_printf("FT: %X", -3456);  // negnum
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %X", -3456);  // negnum
	printf("\nRet: %d\n", ret);

// POINTER ADDRESS
	ft_printf(MAGENTA"\n == TEST '%%p' ==\n"NC);
	ret = ft_printf("FT: %p", &str);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %p", &str);
	printf("\nRet: %d\n", ret);

	ft_printf(MAGENTA"\n == TEST '%%p' ==\n"NC);
	ret = ft_printf("FT: %p %p", strptr, strptr);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %p %p", strptr, strptr);
	printf("\nRet: %d\n", ret);

// UNSINT
	ft_printf(CYAN"\n == TEST '%%u' > 0 ==\n"NC);
	ret = ft_printf("FT: %u", 1345334511);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %u", 1345334511);
	printf("\nRet: %d\n", ret);

	ft_printf(CYAN"\n == TEST '%%u' == 0 ==\n"NC);
	ret = ft_printf("FT: %i", 0);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %i", 0);
	printf("\nRet: %d\n", ret);

	return (0);
}
