/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:50:26 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/23 20:43:17 by mvisca-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

// Main function
int		ft_printf(const char *format, ...);

// Linked list management
int		ft_addchar(t_list **s_clst, const char *format);
int		ft_addcharva(t_list **s_clst, va_list params);
int		ft_addstring(t_list **s_clst, va_list params);
int		ft_addhex(t_list **s_clst, va_list params, char x);
/*
int	ft_addhexupper(t_list **s_clst, va_list params, const char *format);
int	ft_addint(t_list **s_clst, va_list params, const char *format);
int	ft_addnum(t_list **s_clst, va_list params, const char *format);
int	ft_addunsint(t_list **s_clst, va_list params, const char *format);
*/

// Aux functions
void	ft_del(void *cont);

#endif
