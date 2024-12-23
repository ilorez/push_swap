/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:27:57 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 18:06:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/libft.h"

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
