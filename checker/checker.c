/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:35:29 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/26 10:03:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"

int ft_found_err(t_list **s_a,t_list **s_b, t_error_code err)
{
	ft_print_error(err);
	ft_lstclear(s_a, free);
	ft_lstclear(s_b, free);
  return (0);
}

int ft_read_run_oprs(t_list **s_a,t_list **s_b, t_error_code err)
{
  t_operations type;
  char    *line;

  while ((line = get_next_line(0)))
  {
    if (!(type = ft_get_type(line)))
    {
        err = ERR_INVALID_OPERATION;
        free(line);
        break;
    }
    ft_run_type(s_a, s_b, type);
    free(line);
  }
  if(!err && ft_lstsize(*s_b) != 0)
	  err = ERR_STACK_B_NOT_EMPTY;
  if (err)
    return (ft_found_err(s_a, s_b, err));
  if (ft_is_sorted(*s_a, 1))
    ft_printf("\e[38;2;0;255;0mOK\n");
  else
    ft_printf("\e[38;2;255;0;0mKO\n");
  ft_lstclear(s_a, free);
	ft_lstclear(s_b, free);
  return (0);
}

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
		if (err_code == ERR_SUCCESS)
			err_code = ERR_MALLOC_FAIL;
  if (err_code)
    return (ft_found_err(&stack_a, &stack_b, err_code));
  return (ft_read_run_oprs(&stack_a, &stack_b, err_code));
}
