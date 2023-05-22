#include "../ft_printf.h"

void	ft_del(void *cont)
{
	ft_bzero((void *)cont, ft_strlen((char *)cont));
	free(cont);
}
