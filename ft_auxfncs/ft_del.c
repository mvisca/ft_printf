#include "ft_printd.h"
#include "ft_libft/libft.h"

void	ft_del(char *cont)
{
	ft_bzero((void *)cont, ft_strlen((char *)cont));
}
