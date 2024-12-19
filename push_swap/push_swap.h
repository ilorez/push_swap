/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:35:08 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 18:05:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#ifndef INT_MAX
# define INT_MAX 2147483647
#endif

#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

t_bool	ft_create_stack(int ac, char **av, t_list **stack_a);
t_bool	ft_free_list_of_strs(char **strs);
int ft_print_stack(t_list *stack);

// operations (allowed actions)
void ft_op_sx(t_list **stack); // sa sb
void ft_op_rx(t_list **stack); // ra rb
void ft_op_rrx(t_list **stack); // rra rrb
void ft_op_px(t_list **stack_a, t_list **stack_b); // pa pb
void ft_op_rr(t_list **stack_a, t_list **stack_b); // call rx for stack A and B
void ft_op_rrr(t_list **stack_a, t_list **stack_b); // call rrx for stack A and B

#endif
