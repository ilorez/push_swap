/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:37:36 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/24 09:27:27 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"

t_bool	ft_is_sorted(t_list *stack, int order)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (*((int *)stack->content) * order > *((int *)stack->next->content)
			* order)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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
