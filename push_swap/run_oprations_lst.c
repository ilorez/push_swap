/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_oprations_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:38:56 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 16:05:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"
#include "./lst_oprs/oprs.h"

static void	_ft_run_type(t_list **s_a, t_list **s_b, t_operations type)
{
	if (type == RB)
		ft_op_rx(s_b);
	else if (type == RRB)
		ft_op_rrx(s_b);
	else if (type == RA)
		ft_op_rx(s_a);
	else if (oprs == RRA)
		ft_op_rrx(s_a);
	else if (oprs == RR)
		ft_op_rr(s_a, s_b);
	else if (oprs == RRR)
		ft_op_rrr(s_a, s_b);
	else if (oprs == PA)
		ft_op_px(s_b, s_a);
	else if (oprs == PB)
		ft_op_px(s_a, s_b);
	else if (oprs == SA)
		ft_op_sx(s_a);
	else if (oprs == SB)
		ft_op_sx(s_b);
}

t_bool	ft_run_oprs_lst(t_list **s_a, t_list **s_b, t_list *oprs)
{
  if (!oprs) 
    return (1);
  char *str = "SA:SB:PA:PB:RA:RB:RR:RRA:RRB:RRR";
  char **commands = ft_split(str, ':');
	while (*oprs)
	{
    if (!oprs->content->type)
    {
		  oprs = oprs->next;
      continue;
    }
		while (oprs->content->times)
		{
			ft_printf("%s\n", str[oprs->content->type - 1]);
      _ft_run_type(s_a, s_b, oprs->content->type);
      oprs->content->times--;
		}
		oprs = oprs->next;
	}
  ft_free_str_lst(commands);
  ft_lstclear(&oprs, free);
	return (1);
}
