/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:51:01 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/23 13:14:43 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "./error_manager.h"
#include "./push_swap.h"

int	main(int ac, char *av[])
{
	t_list			*stack_a;
	t_list			*stack_b;
	t_error_code	err_code;

	stack_a = NULL;
	stack_b = NULL;
	err_code = ERR_SUCCESS;
	if (ac == 1)
		return (0);
	if (!ft_create_stack(ac, av, &stack_a, &err_code))
	{
		if (err_code == ERR_SUCCESS)
			err_code = ERR_MALLOC_FAIL;
		ft_print_error(err_code);
		ft_lstclear(&stack_a, free);
		return (0);
	}
	ft_sort_stack(&stack_a, &stack_b);
	ft_print_stack(stack_a);
  if (ft_is_sorted(stack_a, 1))
    ft_printf("\e[38;2;0;255;0m it's sorted :c\n");
  else
    ft_printf("\e[38;2;255;0;0m it's Not sorted :c\n");

	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
