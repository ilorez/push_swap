/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:34:59 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/27 14:55:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_sum_rxx(int rxx[])
{
	int	sum;
	int	tmp[4];

	ft_memcpy(tmp, rxx, 4 * sizeof(int));
	sum = 0;
	while (tmp[0] && tmp[1])
	{
		sum++;
		tmp[0]--;
		tmp[1]--;
	}
	while (tmp[0]-- > 0 || tmp[1]-- > 0)
		sum++;
	while (tmp[2] && tmp[3])
	{
		sum++;
		tmp[2]--;
		tmp[3]--;
	}
	while (tmp[2]-- > 0 || tmp[3]-- > 0)
		sum++;
	return (sum);
}

t_list	*ft_create_oprs(int *rxx)
{
	t_list	*oprs;

	oprs = ft_lstnew(ft_oprnew(1, PB));
	while (rxx[0] && rxx[1])
	{
		ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew(1, RR)));
		rxx[0]--;
		rxx[1]--;
	}
	while (rxx[2] && rxx[3])
	{
		ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew(1, RRR)));
		rxx[2]--;
		rxx[3]--;
	}
	while (rxx[0]-- > 0)
		ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew(1, RA)));
	while (rxx[1]-- > 0)
		ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew(1, RB)));
	while (rxx[3]-- > 0)
		ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew(1, RRB)));
	while (rxx[2]-- > 0)
		ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew(1, RRA)));
	return (oprs);
}

void	ft_rotate_to_sort(t_list **stack, int size)
{
	int		min_pos;
	t_list	*oprs;

	min_pos = ft_get_min_pos(*stack, *(int *)((*stack)->content));
	if (min_pos < (size - min_pos))
		oprs = ft_lstnew(ft_oprnew(min_pos, RA));
	else
		oprs = ft_lstnew(ft_oprnew(size - min_pos, RRA));
	ft_run_oprs_lst(stack, NULL, oprs);
	ft_lstclear(&oprs, free);
}

static void	ft_return_num_to_stack_a(t_list **s_a, t_list **s_b, int la)
{
	t_list	*oprs;
	int		num;
	int		b_pos;

	oprs = ft_lstnew(ft_oprnew(1, PA));
	num = *(int *)(*s_b)->content;
	b_pos = ft_get_pos_of(*s_a, la, num);
	if ((la - b_pos) <= b_pos)
		ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew((la - b_pos), RRA)));
	else
		ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew(b_pos, RA)));
	ft_run_oprs_lst(s_a, s_b, oprs);
	ft_lstclear(&oprs, free);
}

void	ft_return_to_stack_a(t_list **s_a, t_list **s_b, int la, int lb)
{
	while (*s_b)
	{
		ft_return_num_to_stack_a(s_a, s_b, la);
		la++;
		lb--;
	}
}
