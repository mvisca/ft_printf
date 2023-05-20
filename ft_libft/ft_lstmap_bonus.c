/* ************************************************************************** */
/*																			  */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:12:13 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/14 13:33:48 by mvisca-g         ###   ########.fr       */
/*																	          */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*cont;

	head = NULL;
	while (lst)
	{
		cont = f(lst->content);
		new = ft_lstnew(cont);
		if (!new)
		{
			del(cont);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
