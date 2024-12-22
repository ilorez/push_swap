/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:14:33 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/22 17:03:17 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "./lst_oprs/oprs.h"
#include "push_swap.h"


int   _ft_get_sum_rxx(int rxx[])
{
  int sum;
  int tmp[4];

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

void  ft_get_rxx_best(int rxx[], int rxx_b[])
{
  int b_sum;
  int t_sum;
  int b_rxx[4];
  int t_rxx[4];


  ft_memcpy(b_rxx, rxx, 4 * sizeof(int));
  // s1: min(ra, rra) min(rb, rrb)
  if (rxx[0] < rxx[2])
    b_rxx[2] = 0;
  else 
    b_rxx[0] = 0;
  if (rxx[1] < rxx[3])
    b_rxx[3] = 0;
  else 
    b_rxx[1] = 0;
  b_sum = _ft_get_sum_rxx(b_rxx);

  //s2: ra rb
  ft_memcpy(t_rxx, rxx, 4 * sizeof(int));
  t_rxx[2] = 0;
  t_rxx[3] = 0;
  t_sum = _ft_get_sum_rxx(t_rxx);
  if (t_sum < b_sum)
  {
    b_sum = t_sum;
    ft_memcpy(b_rxx, t_rxx, 4 * sizeof(int));
  }

  //s3: rra rrb
  ft_memcpy(t_rxx, rxx, 4 * sizeof(int));
  t_rxx[0] = 0;
  t_rxx[1] = 0;
  t_sum = _ft_get_sum_rxx(t_rxx);
  if (t_sum < b_sum)
  {
    b_sum = t_sum;
    ft_memcpy(b_rxx, t_rxx, 4 * sizeof(int));
  }

  // after get b_sum and b_rxx which is best senario for current number 
  // now let's test it with best senario in all past numbers
  if (rxx_b[0] != -1 && b_sum > rxx_b[4])
    return ;
  ft_memcpy(rxx_b, b_rxx, 4 * sizeof(int));
  rxx_b[4] = b_sum;
}

t_list *ft_create_oprs(int *rxx)
{
  t_list *oprs;

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

// rxx:
  // 0: ra
  // 1: rb
  // 2: rra
  // 3: rrb
t_list  *ft_get_best_moves(t_list *s_a, t_list *s_b, int la, int lb)
{
  int num;
  int rxx[4];
  int rxx_best[5];

  rxx[0] = 0;
  rxx_best[0] = -1;
  while (s_a)
  {
    num = *(int *)(s_a->content);
    rxx[1] = ft_get_pos_of(s_b, lb, num);
    rxx[2] = la - rxx[0];
    rxx[3] = lb - rxx[1];
    ft_get_rxx_best(rxx, rxx_best);
    if (rxx_best[4] < 3)
      return ft_create_oprs(rxx_best);
    rxx[0]++;
    s_a = s_a->next;
  }
  return ft_create_oprs(rxx_best);
}

void ft_rotate_to_sort(t_list **stack, int size)
{
  int min_pos;
  t_list  *oprs;
  
  min_pos = ft_get_min_pos(*stack, *(int *)((*stack)->content));
  if (min_pos < (size - min_pos))
    oprs = ft_lstnew(ft_oprnew(min_pos, RA));
  else
    oprs = ft_lstnew(ft_oprnew(size - min_pos, RRA));
  ft_run_oprs_lst(stack, NULL, oprs);
  ft_lstclear(&oprs, free);
}


void  ft_return_num_to_stack_a(t_list **s_a, t_list **s_b, int la, int lb)
{
  t_list *oprs;
  int num;
  int b_pos;

  oprs = ft_lstnew(ft_oprnew(1, PA));
  num = *(int *)(*s_b)->content;
  b_pos = ft_get_pos_of(*s_a, la, num);
  if (b_pos > (la - b_pos))
    ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew((la - b_pos), RRA)));
  else
    ft_lstadd_front(&oprs, ft_lstnew(ft_oprnew(b_pos, RA)));
  ft_run_oprs_lst(s_a, s_b, oprs);
  ft_lstclear(&oprs, free);
}

void  ft_return_to_stack_a(t_list **s_a, t_list **s_b, int la, int lb)
{
  while (*s_b)
  {
    ft_return_num_to_stack_a(s_a, s_b, la, lb);
    la++;
    lb--;
  }
}

t_bool  ft_sort_more(t_list **s_a, t_list **s_b, int size)
{
  t_list *oprs;
  int size_b;

  // start by pussing first two
  ft_op_px(s_a, s_b);
  size_b = 1;
  ft_printf("PB\n");
  if (size > 4 && size--)
  {
    ft_printf("PB\n");
    ft_op_px(s_a, s_b);
  }
  while (--size > 3 && ++size_b)
  {
    oprs = ft_get_best_moves(*s_a, *s_b, size, size_b);
    ft_run_oprs_lst(s_a, s_b, oprs);
    ft_lstclear(&oprs, free);
    if (ft_is_sorted(*s_a, 1))
      break;
  }
  ft_sort_three(s_a);
  ft_return_to_stack_a(s_a, s_b, ft_lstsize(*s_a), ft_lstsize(*s_b));
  ft_rotate_to_sort(s_a, ft_lstsize(*s_a));
  return (1);
  // let's make it back to stack a
}
