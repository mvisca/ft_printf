/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:32:52 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/26 18:59:26 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
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
