/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:37:36 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/26 10:29:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_bool.h"

t_bool	ft_is_sorted(t_list *stack, int order)
{
	if (!stack)
		return (1);
	while (stack && stack->next)
	{
		if (*((int *)stack->content) * order > *((int *)stack->next->content)
			* order)
			return (0);
		stack = stack->next;
	}
	return (1);
}
