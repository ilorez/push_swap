/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:36:58 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 16:08:34 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"

// swap first two element in stack
void ft_op_sx(t_list **stack)
{
  t_list  *swap;
  if (!stack)
    return ;
  if (*stack && (*stack)->next)
  {
    swap = (*stack)->next;
    (*stack)->next = swap->next;
    swap->next = *stack;
    *stack = swap;
  }
}

// take first element in stack a and put it stack b
void ft_op_px(t_list **stack_a, t_list **stack_b)
{
  t_list  *swap;

  if (!stack_a || !stack_b)
    return ;
  if (*stack_a)
  {
    swap = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
    *stack_a = swap;
  }
}

void ft_op_rx(t_list **stack)
{
  void  *swap;
  t_list *last;


  if (!stack)
    return ;
  last = ft_lstlast(*stack);
  swap = (*stack)->content;
  (*stack)->content = last->content;
  last->content = swap;
}
//void ft_op_rrx(t_list **stack); // rra rrb
//void ft_op_rr(t_list **stack_a, t_list **stack_b); // call rx for stack A and B
//void ft_op_rrr(t_list **stack_a, t_list **stack_b); // call rrx for stack A and B





