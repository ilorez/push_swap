/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:14:33 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/23 12:03:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "./lst_oprs/oprs.h"
#include "push_swap.h"

// s1: min(ra, rra) min(rb, rrb)
void	ft_senario_one(int rxx[], int b_rxx[], int *b_sum)
{
	if (rxx[0] < rxx[2])
		b_rxx[2] = 0;
	else
		b_rxx[0] = 0;
	if (rxx[1] < rxx[3])
		b_rxx[3] = 0;
	else
		b_rxx[1] = 0;
	*b_sum = ft_get_sum_rxx(b_rxx);
}

// s2: ra rb
// s3: rra rrb
void	ft_senario(int rxx[], int b_rxx[], int *b_sum, t_bool is_s2)
{
	int	t_sum;
	int	t_rxx[4];

	ft_memcpy(t_rxx, rxx, 4 * sizeof(int));
	if (is_s2)
	{
		t_rxx[2] = 0;
		t_rxx[3] = 0;
	}
	else
	{
		t_rxx[0] = 0;
		t_rxx[1] = 0;
	}
	t_sum = ft_get_sum_rxx(t_rxx);
	if (t_sum < *b_sum)
	{
		*b_sum = t_sum;
		ft_memcpy(b_rxx, t_rxx, 4 * sizeof(int));
	}
}

// after get b_sum and b_rxx which is best senario for current number
// we test it with best senario in all past numbers
void	ft_get_rxx_best(int rxx[], int rxx_b[])
{
	int	b_sum;
	int	b_rxx[4];

	ft_memcpy(b_rxx, rxx, 4 * sizeof(int));
	ft_senario_one(rxx, b_rxx, &b_sum);
	ft_senario(rxx, b_rxx, &b_sum, true);
	ft_senario(rxx, b_rxx, &b_sum, false);
	if (rxx_b[0] != -1 && b_sum > rxx_b[4])
		return ;
	ft_memcpy(rxx_b, b_rxx, 4 * sizeof(int));
	rxx_b[4] = b_sum;
}

/*
 * ft_sort_more
 *
 * */
t_bool	ft_sort_more(t_list **s_a, t_list **s_b, int size)
{
	t_list	*oprs;
	int		size_b;

	ft_op_px(s_a, s_b);
	size_b = 1;
	ft_printf("pb\n");
	if (size > 4 && size--)
	{
		ft_printf("pb\n");
		ft_op_px(s_a, s_b);
	}
	while (--size > 3 && ++size_b)
	{
		oprs = ft_get_best_moves(*s_a, *s_b, size, size_b);
		ft_run_oprs_lst(s_a, s_b, oprs);
		ft_lstclear(&oprs, free);
		if (ft_is_sorted(*s_a, 1))
			break ;
	}
	ft_sort_three(s_a);
	ft_return_to_stack_a(s_a, s_b, ft_lstsize(*s_a), ft_lstsize(*s_b));
	ft_rotate_to_sort(s_a, ft_lstsize(*s_a));
	return (1);
}
