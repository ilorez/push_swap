/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:35:29 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/27 17:22:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_found_err(t_list **s_a, t_list **s_b, t_error_code err)
{
	ft_print_error(err);
	ft_lstclear(s_a, free);
	ft_lstclear(s_b, free);
	return (0);
}

int	ft_read_run_oprs(t_list **s_a, t_list **s_b, t_error_code err)
{
	t_operations	type;
	char			*line;

	line = get_next_line(0);
	while (line)
	{
		type = ft_get_type(line);
		if (!type)
		{
			err = ERR_INVALID_OPERATION;
			break ;
		}
		ft_run_type(s_a, s_b, type);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (err)
		return (ft_found_err(s_a, s_b, err));
	return (1);
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
	if (!ft_read_run_oprs(&stack_a, &stack_b, err_code))
		return (0);
	if (ft_lstsize(stack_b) == 0 && ft_is_sorted(stack_a, 1))
		ft_printf("\e[38;2;0;255;0mOK\n");
	else
		ft_printf("\e[38;2;255;0;0mKO\n");
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
