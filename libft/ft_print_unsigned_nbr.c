/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:23:43 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/02 16:16:10 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_nbr(unsigned int n)
{
	int	out_len;

	out_len = 0;
	if (n >= 10)
	{
		out_len += ft_print_unsigned_nbr(n / 10);
		out_len += ft_print_char(n % 10 + '0');
	}
	else
		out_len += ft_print_char(n + '0');
	return (out_len);
}
