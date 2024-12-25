/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:38:56 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/25 16:23:11 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_utils.h"

void	ft_run_type(t_list **s_a, t_list **s_b, t_operations type)
{
	if (type == RB)
		ft_op_rx(s_b);
	else if (type == RRB)
		ft_op_rrx(s_b);
	else if (type == RA)
		ft_op_rx(s_a);
	else if (type == RRA)
		ft_op_rrx(s_a);
	else if (type == RR)
		ft_op_rxx(s_a, s_b, false);
	else if (type == RRR)
		ft_op_rxx(s_a, s_b, true);
	else if (type == PA)
		ft_op_px(s_b, s_a);
	else if (type == PB)
		ft_op_px(s_a, s_b);
	else if (type == SA)
		ft_op_sx(s_a);
	else if (type == SB)
		ft_op_sx(s_b);
}
