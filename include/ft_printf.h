/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:50:26 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/31 19:31:34 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <libft.h>

// Main function
int	ft_printf(const char *format, ...);

// Linked list management
int	ft_putchar(va_list params, int *i);
int	ft_putstr(va_list params, int *i);
int	ft_putint(va_list params, int *i);
int	ft_putunsint(va_list params, int *i);
int	ft_putptr(va_list params, int *i, char mode);
int	ft_puthex(va_list params, int *i, char mode);

#endif
