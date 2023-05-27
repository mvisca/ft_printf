/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:50:26 by mvisca-g          #+#    #+#             */
/*   Updated: 2023/05/27 21:14:20 by mvisca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "ft_libft/libft.h"

// Main function
int ft_printf(const char *format, ...);

// Linked list management
int ft_putformat(const char *format, int *i);

#endif
