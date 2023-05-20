#include "ft_printf.h"
#include "ft_libft/libft.h"

int	ft_addchar(t_list clst, const char *format)
{
	int		control;
	char	*content;
	t_list	new;

	control = 0;
	content = (char *) ft_calloc (sizeof(char) * 2);
	if (content)
	{
		content[0] = *format;
		control = 1;
		new = ft_lstnew((void *)content);
		if (!new)
		{
			ft_del(content);
			free(content);
			control = 0;
		}
		ft_lstadd_back(&clst, new);
	}
	return (control);
}
