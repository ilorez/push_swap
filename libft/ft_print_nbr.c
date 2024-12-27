/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:18:16 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/02 16:17:29 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	long	n;
	int		out_len;

	n = nbr;
	out_len = 0;
	if (n < 0)
	{
		out_len += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		out_len += ft_print_nbr(n / 10);
	out_len += ft_print_char(n % 10 + 48);
	return (out_len);
}
