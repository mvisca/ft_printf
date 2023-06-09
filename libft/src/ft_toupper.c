/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:38:10 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/04 14:07:16 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ((unsigned char) c >= 'a' && (unsigned char) c <= 'z')
	{
		return (c -= 32);
	}
	return (c);
}
