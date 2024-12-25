/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:44:49 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/16 14:21:12 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// includes
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

// used functions
int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_nbr(int nbr);
int	ft_print_str(char *str);
int	ft_print_ptr(void *n);
int	ft_print_unsigned_nbr(unsigned int n);
int	ft_print_hexa(unsigned long nbr, char *base);

#endif
