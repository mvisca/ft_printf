/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:25:53 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/09 19:08:05 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*current_node;

	current_node = *lst;
	while (current_node)
	{
		next_node = current_node->next;
		del(current_node->content);
		free(current_node);
		current_node = next_node;
	}
	*lst = NULL;
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
                if (tmp && tmp->content)
                                        printf ("%s\n", (char *)tmp->content);
                tmp = tmp->next;
        }
        printf ("SIZE=%d\n", ft_lstsize(head));
        printf ("LAST=%s\n", (char *)(ft_lstlast(head))->content);
        ft_lstclear(
	    head = ft_lstnew(s1);
        head->next = ft_lstnew(s2);
        ft_lstadd_front(&head, ft_lstnew(ft_strdup("Primero")));
        ft_lstadd_back(&head, ft_lstnew(ft_strdup("Ultimo")));
        ft_lstadd_back(&head, ft_lstnew(ft_strdup("Borrable")));
        ft_lstadd_back(&head, ft_lstnew(ft_strdup("Otro")));
        tmp = head;
        while (tmp)
        {
                if (tmp && tmp->content)
                                        printf ("%s\n", (char *)tmp->content);
                tmp = tmp->next;
        }
        printf ("SIZE=%d\n", ft_lstsize(head));
        printf ("LAST=%s\n", (char *)(ft_lstlast(head))->content);
        return (0);
}
*/
