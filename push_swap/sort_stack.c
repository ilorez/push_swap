/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:35:04 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/21 13:40:20 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"

t_list  *ft_get_best_moves(t_list *s_a, t_list *s_b, int size)
{
  int num;
  int rxx[4];
  t_list  *head;
  int i;
  int j;


  i = 0;
  j = 0;
  head = s_a;
  while (*head)
  {
    num = *(int *)((head)->content);
    j = ft_get_pos_of(s_b, num);
    moves = ft_senario_one(s_a, s_b, size);
    *tmp_moves = ft_senario_two(s_a, s_b, size); 
    if (ft_lstsize(moves)
    i++;
  }

}


t_bool  ft_sort_more(t_list **s_a, t_list **s_b, int size)
{
  t_list *oprs;
  // start by pussing first two
  ft_op_px(s_a, s_b);
  if (size > 4 && size--)
    ft_op_px(s_a, s_b);
  while (--size > 3)
  {
    oprs = ft_get_best_moves(*s_a, *s_b, size);
    ft_run_oprs_lst(s_a, s_b, oprs);
    if (ft_is_sorted(s_a))
      break;
  }
  // let's make it back to stack a
}

t_bool ft_sort_stack(t_list **s_a, t_list **s_b)
{
  int size;

  if (!s_a || !s_b)
    return (0);
  if (ft_is_sorted(*s_a, 1))
    return (1);
  size = ft_lstsize(*s_a);
  if (size == 2)
    ft_sort_two(s_a);
  else if (size == 3)
    ft_sort_three(s_a);
  else 
    ft_printf("\n----oo it's not 3\n");
  return (1);
}
