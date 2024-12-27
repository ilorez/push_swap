/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:38:56 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/27 14:55:57 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_run_oprs_lst(t_list **s_a, t_list **s_b, t_list *oprs_lst)
{
	char	*str;
	char	**commands;

	if (!oprs_lst)
		return (1);
	str = "sa:sb:pa:pb:ra:rb:rr:rra:rrb:rrr";
	commands = ft_split(str, ':');
	while (oprs_lst)
	{
		if (!((t_opr *)oprs_lst->content)->type)
		{
			oprs_lst = oprs_lst->next;
			continue ;
		}
		while (((t_opr *)oprs_lst->content)->times)
		{
			ft_printf("%s\n", commands[((t_opr *)oprs_lst->content)->type - 1]);
			ft_run_type(s_a, s_b, ((t_opr *)oprs_lst->content)->type);
			((t_opr *)oprs_lst->content)->times--;
		}
		oprs_lst = oprs_lst->next;
	}
	ft_free_str_lst(commands);
	return (1);
}
