/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:37:36 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/25 15:41:09 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_bool.h"

t_bool	ft_is_between(int n, int a, int b)
{
	if ((a > b && n > b && n < a) || (a < b && n < b && n > a))
		return (true);
	return (false);
}

t_bool	ft_is_between_desc(int n, int a, int b)
{
	if (a > b && n > b && n < a)
		return (true);
	return (false);
}
