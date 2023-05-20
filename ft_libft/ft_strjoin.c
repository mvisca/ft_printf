/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:21:55 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/04 14:17:33 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*new;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	new = (char *) malloc (sizeof(char) * (len1 + len2 + 1));
	if (new)
	{
		while (i < (len1 + len2))
		{
			if (i < len1)
				*(new + i) = *(s1 + i);
			else
				*(new + i) = *(s2 + i - len1);
			i++;
		}
		*(new + i) = '\0';
	}
	return (new);
}

/*
int main() {
    char str1[] = "Hello ";
    char str2[] = "World";
    char *result = ft_strjoin(str1, str2);

    printf("Result: %s\n", result);

    free(result);

    return 0;
}
*/
