#include "ft_printf.h"



	
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
