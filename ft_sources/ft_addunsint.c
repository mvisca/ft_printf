/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:38:05 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/26 15:54:54 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_makeuitoa(unsigned int ncpy, char *tmp)
{
	while (ncpy / 10)
	{
		ft_memmove((tmp + 1), tmp, ft_strlen(tmp));
		tmp[0] = ncpy % 10 + '0';
		ncpy = ncpy / 10;
	}
	return (tmp);
}

char	*ft_uitoa(unsigned int n)
{
	char	*tmp;
	char	*res;

	if (n == 4294967295)
		return (ft_strdup("4294967295"));	
	if (n == 0)
		return (ft_strdup("0"));
	tmp = (char *) ft_calloc (21, sizeof(char));
	if (tmp == NULL)
		return (0);
	ft_makeuitoa(n, tmp);
	res = ft_strdup(tmp);
	free(tmp);
	return (res);
}

int	ft_addunsint(t_list **s_clst_ptr, va_list params)
{
	unsigned int	value;
	int				control;
	int				i;
	char			*num;

	control = 1;
	i = 0;
	num = NULL;
	value = va_arg(params, int);
	if (!value)
		control = ft_addchar(s_clst_ptr, "0");
	else
	{
		num = ft_uitoa(value);
		if (!num)
			return (0);
		while (control && num[i])
			control = ft_addchar(s_clst_ptr, &num[i++]);
	}
	if (control)
		control++;
	free(num);
	return (control);
}
