/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:03:46 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/23 10:39:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "t_bool.h"
#include "libft.h"
#include "error_manager.h"
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

static t_bool	_ft_is_dup(t_list *stack, t_list *node)
{
	while (stack)
	{
		if (*((int *)stack->content) == *((int *)node->content))
			return (true);
		stack = stack->next;
	}
	return (false);
}

static t_list	*_ft_get_node(char *str_num, t_error_code *err_code)
{
	long long	num;
	t_list		*new_num;
	int			*int_num;

	if (!_ft_is_valid(str_num))
	{
		*err_code = ERR_INVALID_ARG;
		return (NULL);
	}
	num = ft_atol(str_num);
	if (num > INT_MAX || num < INT_MIN)
	{
		*err_code = ERR_OUT_INT_RANGE;
		return (NULL);
	}
	int_num = malloc(sizeof(int));
	if (!int_num)
		return (false);
	*int_num = (int)num;
	new_num = ft_lstnew((int_num));
	if (!new_num)
		return (NULL);
	return (new_num);
}

static t_bool	_ft_loop_nums(char **str_nums, t_list **s, t_error_code *e_c)
{
	t_list	*new_num;
	int		i;

	i = 0;
	while (str_nums[i])
	{
		new_num = _ft_get_node(str_nums[i++], e_c);
		if (!new_num)
			return ((t_bool)ft_free_str_lst(str_nums));
		if (_ft_is_dup(*s, new_num))
		{
			*e_c = ERR_DUPLICATED_ARG;
			return ((t_bool)ft_free_str_lst(str_nums));
		}
		ft_lstadd_back(s, new_num);
	}
	return (true);
}

t_bool	ft_create_stack(int ac, char **av, t_list **stack,
		t_error_code *err_code)
{
	char	**str_nums;
	int		j;

	j = 1;
	while (--ac > 0)
	{
		if (av[j][0] == 0)
		{
			*err_code = ERR_EMPTY_ARG;
			return (false);
		}
		str_nums = ft_split(av[j], ' ');
		j++;
		if (!str_nums)
			return (false);
		if (!_ft_loop_nums(str_nums, stack, err_code))
			return (false);
		ft_free_str_lst(str_nums);
	}
	return (true);
}
