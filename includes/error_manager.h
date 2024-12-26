/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:51:57 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/26 13:01:49 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGER_H
# define ERROR_MANAGER_H

# include "libft.h"

// t_error_code enum
typedef enum s_error_code
{
	ERR_SUCCESS = 0,
	ERR_INVALID_ARG,
	ERR_DUPLICATED_ARG,
	ERR_EMPTY_ARG,
	ERR_OUT_INT_RANGE,
	ERR_MALLOC_FAIL,
	ERR_INVALID_OPERATION,
	ERR_STACK_B_NOT_EMPTY,
	ERR_UNKNOWN,
	ERR_COUNT
}					t_error_code;

// Error message structure
typedef struct t_error_message
{
	t_error_code	code;
	char			*message;
}					t_error_message;

// Function declarations
void				ft_print_error(t_error_code error_code);

#endif
