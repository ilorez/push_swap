/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:36:58 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 15:05:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"

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







