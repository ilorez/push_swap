/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugging.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:27:57 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 09:32:30 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_stack(t_list stack)
{
	int	cound;

	count = ft_printf("==================");
	while (*stack)
		count += ft_printf("|%d|", (int)stack->content);
	count += ft_printf("==================");
	return (count);
}
