/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:28:40 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/02 16:19:42 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long n, char *base)
{
	int	out_len;

	out_len = 0;
	if (n >= 16)
		out_len += ft_print_hexa(n / 16, base);
	out_len += ft_print_char(base[n % 16]);
	return (out_len);
}
