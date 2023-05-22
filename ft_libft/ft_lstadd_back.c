/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:37:17 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/09 17:38:22 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	while ((*list)->next)
		list = &(*list)->next;
	(*list)->next = new;
}

/*
Checked
int     main(void)
{
        char    s1[] = "Hola";
        char    s2[] = "Mundo";
        t_list  *head;
        t_list  *tmp;

        head = ft_lstnew(s1);
        head->next = ft_lstnew(s2);
        ft_lstadd_front(&head, ft_lstnew(ft_strdup("Primero")));
        ft_lstadd_back(&head, ft_lstnew(ft_strdup("Ultimo")));
        ft_lstadd_back(&head, ft_lstnew(ft_strdup("Borrable")));
        ft_lstadd_back(&head, ft_lstnew(ft_strdup("Otro")));
        tmp = head;
        while (tmp)
        {
                printf ("%s\n", (char *)tmp->content);
                tmp = tmp->next;
        }
        printf ("SIZE=%d\n", ft_lstsize(head));
        printf ("LAST=%s\n", (char *)(ft_lstlast(head))->content);
        return (0);
}
*/
