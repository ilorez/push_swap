/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:48:41 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/27 17:57:26 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_manager.h"

void	ft_print_error(t_error_code error_code)
{
	t_error_message	err_msgs[ERR_COUNT];

	err_msgs[ERR_SUCCESS] = (t_error_message){ERR_SUCCESS, "OK\n"};
	err_msgs[ERR_INVALID_ARG] = (t_error_message){ERR_INVALID_ARG,
		"Error\n"};
	err_msgs[ERR_DUPLICATED_ARG] = (t_error_message){ERR_DUPLICATED_ARG,
		"Error\n"};
	err_msgs[ERR_EMPTY_ARG] = (t_error_message){ERR_EMPTY_ARG,
		"Error\n"};
	err_msgs[ERR_OUT_INT_RANGE] = (t_error_message){ERR_OUT_INT_RANGE,
		"Error\n"};
	err_msgs[ERR_MALLOC_FAIL] = (t_error_message){ERR_MALLOC_FAIL,
		"Error\n"};
	err_msgs[ERR_INVALID_OPERATION] = (t_error_message){ERR_INVALID_OPERATION,
		"Error\n"};
	err_msgs[ERR_STACK_B_NOT_EMPTY] = (t_error_message){ERR_STACK_B_NOT_EMPTY,
		"Error\n"};
	err_msgs[ERR_UNKNOWN] = (t_error_message){ERR_UNKNOWN,
		"Error\n"};
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	ft_putstr_fd(err_msgs[error_code].message, 2);
}

/*#include <unistd.h>
int	main(int argc, char *argv[]) {
	// Example 1: Direct printing
	if (argc < 2) {
		print_error(ERR_EMPTY_ARG);
		return (1);
	}
	print_error(ERR_SUCCESS);
	return (0);
}*/
