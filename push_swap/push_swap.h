/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:35:08 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/23 12:06:33 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

// includes
# include "./error_manager.h"

// create stack
t_bool	ft_create_stack(int ac, char **av, t_list **stack_a,
			t_error_code *err_code);

// sort
t_bool	ft_sort_stack(t_list **stack_a, t_list **stack_b);
t_bool	ft_sort_three(t_list **stack);
t_bool	ft_sort_two(t_list **stack);

// utils
t_bool	ft_is_sorted(t_list *stack, int order);
t_bool	ft_is_between(int n, int a, int b);

// run operations
t_bool	ft_run_oprs_lst(t_list **s_a, t_list **s_b, t_list *oprs_lst);

// debugging
int		ft_print_stack(t_list *stack);

// get pos of
int		ft_get_min_pos(t_list *stack, int min);
int		ft_get_pos_of(t_list *stack, int size, int n);

// operations (allowed actions)
// sa sb
void	ft_op_sx(t_list **stack);
// ra rb
void	ft_op_rx(t_list **stack);
// rrarrb
void	ft_op_rrx(t_list **stack);
// pa pb
void	ft_op_px(t_list **stack_a, t_list **stack_b);
// call rx/rrx for stack A and B
void	ft_op_rxx(t_list **stack_a, t_list **stack_b, t_bool reverse);

// sort more
t_bool	ft_sort_more(t_list **s_a, t_list **s_b, int size);
void	ft_get_rxx_best(int rxx[], int rxx_b[]);
// sort more utils 1
t_list	*ft_get_best_moves(t_list *s_a, t_list *s_b, int la, int lb);
// sort more utils 2
void	ft_return_to_stack_a(t_list **s_a, t_list **s_b, int la, int lb);
void	ft_rotate_to_sort(t_list **stack, int size);
t_list	*ft_create_oprs(int *rxx);
int		ft_get_sum_rxx(int rxx[]);
#endif
