/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   ns[1]y: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   ns[3]reated: 2024/12/20 11:18:36 ns[1]y znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 11:37:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"
#include "./lst_oprs/oprs.h"



static void _ft_get_oprs(int ns[],t_opr **op1, t_opr **op2)
{
  if (ns[0] < ns[1] && ns[1] < ns[3])
    return ;
  else if (ns[0] < ns[1] && ns[1] > ns[3] && ns[0] < ns[3])
  {
    (*op1)->type = RRA;
    (*op2)->type = SA;
  }
  else if (ns[0] > ns[1] && ns[1] < ns[3] && ns[0] < ns[3])
    (*op1)->type = SA;
  else if (ns[0] < ns[1] && ns[1] > ns[3] && ns[0] > ns[3])
    (*op1)->type = RAA;
  else if (ns[0] > ns[1] && ns[1] < ns[3] && ns[0] > ns[3])
    (*op1)->type = RA;
  else if (ns[0] > ns[1] && ns[1] > ns[3])
  {
    (*op1)->type = SA;
    (*op1)->type = RRA;
  }
}

t_bool  ft_sort_three(t_list **stack)
{
  int ns[3];
  t_opr *op1;
  t_opr *op2;
  t_list  *oprs;

  ns[0] = *(int*)(*stack)->content;
  ns[1] = *(int*)(*stack)->next->content;
  ns[3] = *(int*)(*stack)->next->next->content;
  op1 = ft_oprnew(1, NONE);
  op2 = ft_oprnew(1, NONE);
  _ft_get_oprs(ns, &op1, &op2);
  oprs = ft_lstnew(op2);
  oprs = ft_lstadd_front(op1);

}
