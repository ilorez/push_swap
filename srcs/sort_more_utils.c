/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:30:22 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/27 14:56:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rxx:
// 0: ra
// 1: rb
// 2: rra
// 3: rrb
t_list	*ft_get_best_moves(t_list *s_a, t_list *s_b, int la, int lb)
{
	int	num;
	int	rxx[4];
	int	rxx_best[5];

	rxx[0] = 0;
	rxx_best[0] = -1;
	while (s_a)
	{
		num = *(int *)(s_a->content);
		rxx[1] = ft_get_pos_of(s_b, lb, num);
		rxx[2] = la - rxx[0];
		rxx[3] = lb - rxx[1];
		ft_get_rxx_best(rxx, rxx_best);
		if (rxx_best[4] <= 1)
			return (ft_create_oprs(rxx_best));
		rxx[0]++;
		s_a = s_a->next;
	}
	return (ft_create_oprs(rxx_best));
}
