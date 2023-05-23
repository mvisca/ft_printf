/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:37:58 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/23 21:00:56 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_addchar(t_list **s_clst, const char *format)
{
	int		control;
	char	*content;
	t_list	*new;

	control = 0;
	content = (char *) ft_calloc (sizeof(char), 2);
	if (content)
	{
		content[0] = *format;
		content[1] = '\0';
		control = 1;
		new = ft_lstnew(content);
		if (!new)
		{
			ft_del(content);
			free(content);
			control = 0;
			return (control);
		}
		ft_lstadd_back(s_clst, new);
	}
	return (control);
}
