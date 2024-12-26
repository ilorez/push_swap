/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:51:28 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/25 16:53:41 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

// includes
# include "error_manager.h"
# include "libft.h"
# include "oprs.h"
# include "t_bool.h"

// create stack
t_bool	ft_create_stack(int ac, char **av, t_list **stack_a,
			t_error_code *err_code);

// general utils
t_bool	ft_is_sorted(t_list *stack, int order);

// run type
void	ft_run_type(t_list **s_a, t_list **s_b, t_operations type);

// debugging
int		ft_print_stack(t_list *stack);

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

t_list	*ft_create_oprs(int *rxx);
#endif
