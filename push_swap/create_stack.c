/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:03:46 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 18:04:44 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf/ft_printf.h"
#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"

static t_bool	_ft_is_valid(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static t_bool	_ft_is_duplicated(t_list *stack, t_list *node)
{
	while (*stack)
	{
		if (*((int *)stack->content) == *((int *)node->content))
			return (true);
	}
	return (false);
}

static t_list	*_ft_get_node(char *str_num)
{
	long long	num;
	t_list		*new_num;
	int			*int_num;

	if (!_ft_is_valid(str_num))
	{
		ft_printf("Error\nnot all digits\n");
		return (NULL);
	}
	num = ft_atol(str_num);
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_printf("Error\nnot valid number\n \
      found a number out of INT range\n");
		return (NULL);
	}
	int_num = malloc(sizeof(int));
	*int_num = (int)num;
	new_num = ft_lstnew((int_num));
	if (!new_num)
	{
		ft_printf("Error\nnew_num desn't allocated correctly!");
		return (NULL);
	}
	return (new_num);
}

t_bool	ft_create_stack(int ac, char **av, t_list **stack)
{
	char	**str_nums;
	t_list	*new_num;
	int		i;

	while (--ac > 0)
	{
		str_nums = ft_split(av[ac], ' ');
		if (!str_nums)
			return (false);
		i = 0;
		while (str_nums[i])
		{
			new_num = _ft_get_node(str_nums[i++]);
			if (!new_num)
				return ((t_bool)ft_free_str_lst(str_nums));
			if (_ft_is_deplicated(*stack, new_num))
			{
				ft_printf("Error\nfound a duplicate number\n");
				return ((t_bool)ft_free_str_lst(str_nums));
			}
			ft_lstadd_back(stack, new_num);
		}
		ft_free_str_lst(str_nums);
	}
	return (true);
}
