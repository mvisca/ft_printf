/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:30:46 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/16 11:31:47 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
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

static char	**ft_do_split(char **split, const char *s, char c)
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
			split[k] = ft_substr(s, start, i + 1 - start);
			if (!split[k++])
			{
				ft_free_all(split);
				return (NULL);
			}
		}
		i++;
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc (sizeof(char *) * (ft_count(s, c) + 1));
	if (!split)
		return (NULL);
	split = ft_do_split(split, s, c);
	if (!split)
		return (NULL);
	return (split);
}
