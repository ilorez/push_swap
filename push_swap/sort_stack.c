/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:35:04 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 11:18:21 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"
#include "./lst_oprs/oprs.h"

t_bool  ft_is_sorted(t_list *stack, int order)
{
  if (!stack)
    return (0);
  while (stack && stack->next)
  {
    if (*((int *)stack->content) * order > 
      *((int *)stack->next->content) * order)
      return (0)
    stack = stack->next;
  }
  return (1);
}

void _ft_get_oprs(int a, int b, int c,t_opr **op1, t_opr **op2)
{
  if (a < b && b < c)
    return (1);
  if (a < b && b > c && a < c)
  {
    (*op1)->type = RRA;
    (*op2)->type = SA;
  }
  else if (a > b && b < c && a < c)
    (*op1)->type = SA;
  if (a < b && b > c && a > c)
    (*op1)->type = RAA;
  if (a > b && b < c && a > c)
    (*op1)->type = RA;
  if (a > b && b > c)
  {
    (*op1)->type = SA;
    (*op1)->type = RRA;
  }
}

t_bool  ft_sort_three(t_list **stack)
{
  int a;
  int b;
  int c;
  t_opr *op1;
  t_opr *op2;
  t_list  *oprs;

  a = *(int*)(*stack)->content;
  b = *(int*)(*stack)->next->content;
  c = *(int*)(*stack)->next->next->content;
  oprs = NULL;
  


}

t_bool  ft_sort_three(t_list **stack)
{
  int a;
  int b;
  int c;

  a = *(int*)(*stack)->content;
  b = *(int*)(*stack)->next->content;
  c = *(int*)(*stack)->next->next->content;
  // example : 1 2 3
  if (a < b && b < c)
    return (1);

  // example : 1 3 2
  if (a < b && b > c && a < c)
  {
    ft_op_rrx(stack);
    ft_op_sx(stack);
    ft_printf("RRA\nSA");
  }

  // example : 2 1 3
  if (a > b && b < c && a < c)
  {
    ft_op_sx(stack);
    ft_printf("SA");
  }

  // example : 2 3 1
  if (a < b && b > c && a > c)
  {
    ft_op_rrx(stack);
    ft_printf("RAA");
  }
  
  // example : 3 1 2
  if (a > b && b < c && a > c)
  {
    ft_op_rx(stack);
    ft_printf("RA");
  }
  
  // example : 3 2 1
  if (a > b && b > c)
  {
    ft_op_sx(stack);
    ft_op_rrx(stack);
    ft_printf("SA\nRRA");
  }
}

t_bool ft_sort_stack(t_list **s_a, t_list **s_b);
{
  int size;

  if (!s_a || !s_b)
    return (0);
  if (ft_is_sorted(s_a))
    return (1);
  size = ft_lstsize(*s_a);
  if (size)



}
