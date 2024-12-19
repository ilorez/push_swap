/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:51:01 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 09:35:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"

t_bool	ft_is_all_digits(char *str)
{
	while (*str)
		if (!ft_isdigit(*str))
			return (false);
	return (true);
}

t_bool	ft_create_stack(int ac, char **av, t_list *stack_a)
{
	long long	num;
	char		**str_nums;
	char		*tmp;
	t_list		*new_num;

	while (ac--)
	{
		str_nums = ft_split(av[ac]);
		if (!str_nums)
			return (false);
		while (*str_nums)
		{
			if (!ft_is_all_digits(*str_nums))
				return (ft_free_str_lst(str_nums));
			num = ft_atol(*str_nums);
			if (num > INT_MAX || num < INT_MIN)
			{
				ft_printf("Error\nnot valid number\n \
          found a number out of INT range\n");
				return (ft_free_str_lst(str_nums));
			}
			new_num = ft_lstnew(&((int)num));
			if (!new_num)
			{
				ft_printf("Error\nnew_num desn't allocated correctly!");
				return (ft_free_str_lst(str_nums));
			}
			ft_lstadd_front(stack_a, new_num);
			tmp = *str_nums;
			++str_nums;
			free(tmp);
		}
		ft_free_str_lst(str_nums);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_list	stack_a;

	stack_a = NULL;
	if (ac == 1)
		ft_printf("Error\nNo numbers passed!:[\nto pass argument use for example \
%s 1 2 3 4 5", av[0]);
	if (!ft_create_stack(--ac, &av[1], &stack_a))
		ft_lstclear(stack_a, free);
	ft_print_stack(stack_a);
}
