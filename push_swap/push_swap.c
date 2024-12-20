/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:51:01 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/20 09:33:40 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
	{
		ft_printf("Error\nNo numbers passed!:[\nUse:\n  %s 1 2 3 4 5", av[0]);
		return (0);
	}
	if (!ft_create_stack(ac, av, &stack_a))
	{
		ft_printf("stack doesn't created\n");
		ft_lstclear(&stack_a, free);
		return (0);
	}

  ft_sort_stack(&stack_a, &stack_b);
  //ft_op_px(&stack_a, &stack_b);

	//ft_printf("Print Stack A\n");
	//ft_print_stack(stack_a);
	//ft_printf("Print Stack B\n");
	//ft_print_stack(stack_b);
	//ft_printf("running RRR\n");
	//ft_op_rrr(&stack_a, &stack_b);
	ft_printf("====***V***====\n");
	ft_printf("Print Stack A\n");
	ft_print_stack(stack_a);
	ft_printf("Print Stack B\n");
	ft_print_stack(stack_b);

  // clear stacks
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}

