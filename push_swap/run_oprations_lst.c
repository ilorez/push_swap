/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_oprations_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:38:56 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 17:54:44 by znajdaou         ###   ########.fr       */
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
	else if (type == RRA)
		ft_op_rrx(s_a);
	else if (type == RR)
		ft_op_rr(s_a, s_b);
	else if (type == RRR)
		ft_op_rrr(s_a, s_b);
	else if (type == PA)
		ft_op_px(s_b, s_a);
	else if (type == PB)
		ft_op_px(s_a, s_b);
	else if (type == SA)
		ft_op_sx(s_a);
	else if (type == SB)
		ft_op_sx(s_b);
}

t_bool	ft_run_oprs_lst(t_list **s_a, t_list **s_b, t_list *oprs_lst)
{
  if (!oprs_lst) 
    return (1);
  char *str = "SA:SB:PA:PB:RA:RB:RR:RRA:RRB:RRR";
  char **commands = ft_split(str, ':');
	while (oprs_lst)
	{
    if (!((t_opr *)oprs_lst->content)->type)
    {
		  oprs_lst = oprs_lst->next;
      continue;
    }
		while (((t_opr *)oprs_lst->content)->times)
		{
			ft_printf("%s\n", commands[((t_opr *)oprs_lst->content)->type - 1]);
      _ft_run_type(s_a, s_b, ((t_opr *)oprs_lst->content)->type);
      ((t_opr *)oprs_lst->content)->times--;
		}
		oprs_lst = oprs_lst->next;
	}
  ft_free_str_lst(commands);
  ft_lstclear(&oprs_lst, free);
	return (1);
}
