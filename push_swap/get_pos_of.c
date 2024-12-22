/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:22:17 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/22 15:07:49 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "push_swap.h"

int	ft_get_min_pos(t_list *stack, int min)
{
	int	min_i;
	int	num;
	int	i;

	i = 0;
	min_i = 0;
	while (stack)
	{
		num = *(int *)stack->content;
		if (num < min)
		{
			min_i = i;
			min = num;
		}
		i++;
		stack = stack->next;
	}
	return (min_i);
}

// this function always stack that is have more then two numbers
// min: the first element by default
static int	ft_get_right_order(t_list *stack, int min)
{
	t_list	*before_n;
	t_list	*after_n;
	int		min_pos;

	min_pos = ft_get_min_pos(stack, min);
	before_n = NULL;
	after_n = stack;
	while (min_pos--)
	{
		before_n = stack;
		stack = stack->next;
	}
	if (stack->next)
		after_n = stack->next;
	if (!before_n)
		before_n = ft_lstlast(stack);
	if (*(int *)before_n->content > *(int *)after_n->content)
		return (1);
	return (-1);
}

static int	_ft_get_pos(t_list *stack, int n, int o, int f)
{
	int	a;
	int	b;
	int	edge;
	int	i;

	i = 0;
	edge = 0;
	while (stack->next && ++i)
	{
		a = *(int *)stack->content;
		b = *(int *)stack->next->content;
		if ((o == 1 && a > b) || (o == -1 && a < b))
		{
			edge = i;
			stack = stack->next;
			continue ;
		}
		if ((o == 1 && n > a && n < b) || (o == -1 && n < a && n > b))
			return (i);
		stack = stack->next;
	}
	if ((b < f && n > b && n < f) || (f < b && n < b && n > f))
		return (0);
	return (edge);
}

// sl: stack size
int	ft_get_pos_of(t_list *stack, int size, int n)
{
	int	a;
	int	b;
	int	order;
	int	first;

	if (size == 1)
		return (0);
	a = *(int *)stack->content;
	b = *(int *)stack->next->content;
	if (size == 2)
		return ((int)ft_is_between(n, a, b));
	order = ft_get_right_order(stack, a);
	first = a;
	return (_ft_get_pos(stack, n, order, first));
}
