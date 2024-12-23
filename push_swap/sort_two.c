/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:18:03 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/22 17:18:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"

t_bool	ft_sort_two(t_list **stack)
{
	int	ns[2];

	if (!stack)
		return (false);
	if (!*stack || !(*stack)->next)
		return (false);
	ns[0] = *(int *)(*stack)->content;
	ns[1] = *(int *)(*stack)->next->content;
	if (ns[0] > ns[1])
	{
		ft_op_sx(stack);
		ft_printf("sa\n");
	}
	return (true);
}
