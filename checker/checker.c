/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:35:29 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/24 21:02:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"
#include "../push_swap/push_swap.h"
#include "ft_printf.h"
#include "t_bool.h"
#include "libft.h"
#include "../push_swap/error_manager.h"

int	main(int ac, char *av[])
{
	t_list			*stack_a;
	t_list			*stack_b;
  char    *opr;
	t_error_code	err_code;
  t_oprations type;

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
  // read operations from input using get next line and run one by one without createing
  // list because you don't need that
  // use strcmp to find the operation if not found
  // stop program and show error
  // after get command you just send it to run type 
  // after don
  //
	err_code = ERR_SUCCESS;
  while (opr = get_next_line(0))
  {
    type = get_operation_type(opr);
    if (!type)
    {
	    err_code = ERR_INVALID_OPERATION;
      break;
    }
    ft_run_type(s_a, s_b, type);
    free(opr);
  }
  if (err_code)
  {
		ft_print_error(err_code);
    ft_lstclear(&stack_a, free);
	  ft_lstclear(&stack_b, free);
    return (0);
  }
  //if(!ft_is_stack_empty(stack_b))
  //{
	//	ft_print_error(err_code);
  //  ft_lstclear(&stack_a, free);
	//  ft_lstclear(&stack_b, free);
  //  return (0);
  //}
  if (ft_is_sorted(stack_a, 1))
    ft_printf("\e[38;2;0;255;0m it's sorted :c\n");
  else
    ft_printf("\e[38;2;255;0;0m it's Not sorted :c\n");
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
