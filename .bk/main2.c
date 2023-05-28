#include "ft_printf.h"


// POINTER ADDRESS
	ft_printf(BLUE"\n == TEST '%%p' ==\n"NC);
	ret = ft_printf("FT: %p", &str);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %p", &str);
	printf("\nRet: %d\n", ret);

	ft_printf(YELLOW"\n == TEST '%%p' ==\n"NC);
	ret = ft_printf("FT: %p %p", strptr, strptr);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %p %p", strptr, strptr);
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
	
// UNSINT
	ft_printf(CYAN"\n == TEST '%%u' > 0 ==\n"NC);
	ret = ft_printf("FT: %u", 1345334511);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %u", 1345334511);
	printf("\nRet: %d\n", ret);

	ft_printf(GREEN"\n == TEST '%%i' < 0 ==\n"NC);
	ret = ft_printf("FT: %i", -47384);
	printf("\nRet: %d\n", ret);
	ret = printf("OR: %i", -47384);
	printf("\nRet: %d\n", ret);
	
// CORNER CASES
	ft_printf(MAGENTA"\n == TEST CORNER FT %%%%x ==\n"NC);
	ret = ft_printf("%%x");
	printf("\nRet DEL MAIN: %d\n", ret);

	ft_printf(MAGENTA"\n == TEST CORNER FT %%%%X ==\n"NC);
	ret = ft_printf("%%X");
	printf("\nRet DEL MAIN: %d\n", ret);

	ft_printf(MAGENTA"\n == TEST '%(end)' ==\n"NC);
	ret = ft_printf("FT: %");
	printf("\nRet: %d\n", ret);
//	ret = printf("OR: %");
//	printf("\nRet: %d\n", ret);

	return (0);
}
