/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:37:36 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 11:37:43 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
