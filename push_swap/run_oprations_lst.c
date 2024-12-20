/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_oprations_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:38:56 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 12:06:09 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void _ft_run_type(t_list **s_a, t_list **s_b, t_operations type)
{
  if (type == RB) 
        ft_op_rx(s_b);
      else if (type == RRB) 
        ft_op_rrx(s_b);
      else if (type == RA) 
        ft_op_rx(s_a);
      else if (oprs->type == RRA) 
        ft_op_rrx(s_a);
      else if (oprs->type == RR) 
        ft_op_rr(s_a, s_b);
      else if (oprs->type == RRR) 
        ft_op_rrr(s_a, s_b);
      else if (oprs->type == PA) 
        ft_op_px(s_b, s_a);
      else if (oprs->type == PB) 
        ft_op_px(s_a, s_b);
      else if (oprs->type == SA) 
        ft_op_sx(s_a);
      else if (oprs->type == SB) 
        ft_op_sx(s_b);
      

}

t_bool ft_run_oprs_lst(t_list **s_a, t_list **s_b, t_list *oprs)
{
  char *str[] = {"SA", "SB", "PA", "PB", "RA", "RB", "RR", "RRA", "RRB", "RRR"}
  if (!oprs)
    return (1);
  while (*oprs)
  {
    while (oprs->times && oprs->type)
    {
      ft_printf("%s\n", str[oprs->type - 1])
            oprs->times--;
    }
    oprs = oprs->next;
  }
  return (1);
}
