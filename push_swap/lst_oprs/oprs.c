/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:00:05 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 17:36:26 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oprs.h"
#include "../../libft/libft.h"


t_opr *ft_oprnew(int times, t_operations type)
{
  t_opr *my_opr;

  my_opr = (t_opr *)malloc(sizeof(t_opr));

  if (!my_opr)
    return (NULL);
  my_opr->times = times;
  my_opr->type = type;
  return (my_opr);
}




