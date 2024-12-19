/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:35:08 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 14:19:18 by znajdaou         ###   ########.fr       */
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
t_bool	ft_is_valid(char *str);
t_bool	ft_free_list_of_strs(char **strs);
int ft_print_stack(t_list *stack);

#endif
