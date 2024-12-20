/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:01:05 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 17:30:54 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPRS_H
#define OPRS_H

typedef enum s_operations {
  NONE,
  SA,
  SB,
  PA,
  PB,
  RA,
  RB,
  RR,
  RRA,
  RRB,
  RRR
} t_operations;

typedef struct s_opr
{
  int times;
  t_operations type;
} t_opr;

// functions 
t_opr *ft_oprnew(int times, t_operations type);

#endif
