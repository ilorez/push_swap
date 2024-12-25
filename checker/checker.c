/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:35:29 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/25 17:00:36 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"

int	main(int ac, char *av[])
{
	t_list			*stack_a;
	t_list			*stack_b;
  char    *opr;
	t_error_code	err_code;
  t_operations type;

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
	err_code = ERR_SUCCESS;
  opr = get_next_line(0);
  while (opr)
  {
    type = ft_get_type(opr);
    if (!type)
    {
	    err_code = ERR_INVALID_OPERATION;

      break;
    }

    ft_run_type(&stack_a, &stack_b, type);
    free(opr);
    opr = get_next_line(0);
  }
  free(opr);
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
