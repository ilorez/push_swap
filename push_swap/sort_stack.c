/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:35:04 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 18:17:45 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"





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
