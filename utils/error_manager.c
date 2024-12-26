/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:48:41 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/26 10:29:41 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_manager.h"

void	ft_print_error(t_error_code error_code)
{
	t_error_message	error_messages[ERR_COUNT];

	error_messages[ERR_SUCCESS] = (t_error_message){ERR_SUCCESS, "OK\n", 3};
	error_messages[ERR_INVALID_ARG] = (t_error_message){ERR_INVALID_ARG,
		"Error\ninvalid argument\n", 23};
	error_messages[ERR_DUPLICATED_ARG] = (t_error_message){ERR_DUPLICATED_ARG,
		"Error\nduplicated argument\n", 26};
	error_messages[ERR_EMPTY_ARG] = (t_error_message){ERR_EMPTY_ARG,
		"Error\nEmpty argumnet\n", 21};
	error_messages[ERR_OUT_INT_RANGE] = (t_error_message){ERR_OUT_INT_RANGE,
		"Error\nfound a number out of int range\n", 38};
	error_messages[ERR_MALLOC_FAIL] = (t_error_message){ERR_MALLOC_FAIL,
		"Error\nan allocation failed\n", 27};
  error_messages[ERR_INVALID_OPERATION] = (t_error_message){ERR_INVALID_OPERATION,
		"Error\nfound invalid operation\n", 30};
  error_messages[ERR_STACK_B_NOT_EMPTY] = (t_error_message){ERR_STACK_B_NOT_EMPTY,
		"Error\nstack B not empty\n", 24};
	error_messages[ERR_UNKNOWN] = (t_error_message){ERR_UNKNOWN,
		"Error\nUnknown error occurred\n", 29};
	if (error_code < 0 || error_code >= ERR_COUNT)
		error_code = ERR_UNKNOWN;
	write(STDERR_FILENO, error_messages[error_code].message,
		error_messages[error_code].length);
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
