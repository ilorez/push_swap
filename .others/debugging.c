/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:27:57 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/27 15:04:21 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_stack(t_list *stack)
{
	int	count;

	count = ft_printf("==================\n");
	while (stack)
	{
		count += ft_printf("|%d|\n", *((int *)stack->content));
		stack = stack->next;
	}
	count += ft_printf("==================\n");
	return (count);
}
