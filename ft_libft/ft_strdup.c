/* ************************************************************************** */
/*																			  */
/*														:::	  ::::::::        */
/*   ft_strdup.c										:+:	  :+:	:+:       */
/*													+:+ +:+		 +:+	      */
/*   By: mvisca-g <mvisca-g@student.42barcel>	   +#+  +:+	   +#+		      */
/*												+#+#+#+#+#+   +#+		      */
/*   Created: 2023/04/24 11:25:25 by mvisca-g		  #+#	#+#			      */
/*   Updated: 2023/05/15 16:38:58 by mvisca-g         ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup;

	len = ft_strlen((char *)s);
	dup = (char *) malloc (sizeof(char) * (len + 1));
	if (dup)
	{
		i = 0;
		while (*(s + i))
		{
			*(dup + i) = *(s + i);
			i++;
		}
		*(dup + i) = '\0';
	}
	return (dup);
}

/*
int main(void) {
	char *original_str = "Hola mundo";
	char *copied_str = strdup(original_str);
	
	printf("La cadena original es: %s\n", original_str);
	printf("La cadena copiada es: %s\n", copied_str);
	free(copied_str);
	return (0);
}
*/
