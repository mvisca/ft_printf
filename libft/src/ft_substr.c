/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:46:36 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/15 16:39:33 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*scpy;
	char		*sub;
	size_t		i;

	scpy = (char *)s;
	if (ft_strlen(scpy) == 0 || ft_strlen(scpy) < start)
		return ((char *)ft_calloc(1, 1));
	if (ft_strlen(scpy) < start + len)
		len = ft_strlen(scpy) - start;
	sub = (char *) malloc (sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && (unsigned char) *(s + start + i))
	{
		*(sub + i) = *(s + start + i);
		i++;
	}
	*(sub + i) = '\0';
	return (sub);
}

/*
int main() {
    char *str = "Hola.mundo!";
    char *sub = ft_substr(str, 5, 5);

    printf("La cadena original es: %s\n", str);
    printf("La subcadena es: %s\n", sub);

    free(sub);
    return 0;
}
*/
