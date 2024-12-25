/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:37:36 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/25 15:37:56 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_bool.h"
#include "libft.h"

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

