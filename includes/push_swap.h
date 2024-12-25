/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:35:08 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/25 16:21:27 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include "ft_utils.h"

// sort
t_bool	ft_sort_stack(t_list **stack_a, t_list **stack_b);
t_bool	ft_sort_three(t_list **stack);
t_bool	ft_sort_two(t_list **stack, int order);

// utils
t_bool	ft_is_between(int n, int a, int b);
t_bool	ft_is_between_desc(int n, int a, int b);

// get pos of
int		ft_get_min_pos(t_list *stack, int min);
int		ft_get_pos_of(t_list *stack, int size, int n);

// run operations
t_bool	ft_run_oprs_lst(t_list **s_a, t_list **s_b, t_list *oprs_lst);

// sort more
t_bool	ft_sort_more(t_list **s_a, t_list **s_b, int size);
void	ft_get_rxx_best(int rxx[], int rxx_b[]);
// sort more utils 1
t_list	*ft_get_best_moves(t_list *s_a, t_list *s_b, int la, int lb);
// sort more utils 2
void	ft_return_to_stack_a(t_list **s_a, t_list **s_b, int la, int lb);
void	ft_rotate_to_sort(t_list **stack, int size);
int		ft_get_sum_rxx(int rxx[]);
#endif
