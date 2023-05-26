/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:55:11 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/26 19:02:04 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_d_minor_s(size_t *i, size_t *e, size_t n, int *d)
{
	*i = 0;
	*e = n - 1;
	*d = 1;
}

static void	ft_s_minor_d(size_t *i, size_t *e, size_t n, int *d)
{
	*i = n - 1;
	*e = 0;
	*d = -1;
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	size_t		end;
	int			delta;

	if (dest != src)
	{
		if (dest < src)
			ft_d_minor_s(&i, &end, n, &delta);
		else
			ft_s_minor_d(&i, &end, n, &delta);
		while (i != end + delta)
		{
			((char *)dest)[i] = *(((char *) src) + i);
			i += delta;
		}
	}
	return (dest);
}

// d < s mv de d[0] -> d[n]
// s < d mv de d[n] -> d[0]

/*
int	main(void)
{
	char 	s1[] = "01234567890abcdef";
	char 	s2[] = "01234567890abcdef";
	int		a = 5;
	int		b = 2;
	int		l = 4;

//	printf ("ORIGINAL=%s\n", s1);
	ft_memmove(&s1[a], &s1[b], l);

	printf ("MODIFIED=%s\n", s1);

	printf ("La de string.h\n");
	
//	printf ("ORIGINAL=%s\n", s2);
	m e m m o v e(&s2[a], &s2[b], l);

	printf ("MODIFIED=%s\n", s2);
	return (0);
}
*/
