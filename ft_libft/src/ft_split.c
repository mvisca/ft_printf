/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:30:46 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/24 14:01:06 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_all(char **spliter)
{
	int	i;

	i = 0;
	while (spliter[i])
	{
		free(spliter[i]);
		i++;
	}
	free(spliter);
}

static int	ft_count(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_do_split(char **spliter, const char *s, char c)
{
	int		i;
	int		k;
	int		start;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			spliter[k] = ft_substr(s, start, i + 1 - start);
			if (!spliter[k++])
			{
				ft_free_all(spliter);
				return (NULL);
			}
		}
		i++;
	}
	spliter[k] = NULL;
	return (spliter);
}

char	**ft_split(const char *s, char c)
{
	char	**spliter;

	if (!s)
		return (NULL);
	spliter = malloc (sizeof(char *) * (ft_count(s, c) + 1));
	if (!spliter)
		return (NULL);
	spliter = ft_do_split(spliter, s, c);
	if (!spliter)
		return (NULL);
	return (spliter);
}
