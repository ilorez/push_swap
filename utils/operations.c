/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:36:58 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/27 15:03:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

// swap first two element in stack
void	ft_op_sx(t_list **stack)
{
	t_list	*swap;

	if (!stack)
		return ;
	if (*stack && (*stack)->next)
	{
		swap = (*stack)->next;
		(*stack)->next = swap->next;
		swap->next = *stack;
		*stack = swap;
	}
}

// take first element in stack a and put it stack b
void	ft_op_px(t_list **stack_a, t_list **stack_b)
{
	t_list	*swap;

	if (!stack_a || !stack_b)
		return ;
	if (*stack_a)
	{
		swap = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = swap;
	}
}

// this function rotate up by one number stack
void	ft_op_rx(t_list **stack)
{
	t_list	*last;

	if (!stack)
		return ;
	if (*stack && (*stack)->next)
	{
		last = ft_lstlast(*stack);
		last->next = *stack;
		*stack = (*stack)->next;
		last->next->next = NULL;
	}
}

// this function rotate down by one number a stack
void	ft_op_rrx(t_list **stack)
{
	t_list	*b_last;

	if (!stack)
		return ;
	b_last = *stack;
	while (b_last && b_last->next && b_last->next->next)
		b_last = b_last->next;
	if (*stack && (*stack)->next)
	{
		b_last->next->next = *stack;
		*stack = b_last->next;
		b_last->next = NULL;
	}
}

// run rotate up/down for both stacks (A and B)
void	ft_op_rxx(t_list **stack_a, t_list **stack_b, t_bool reverse)
{
	if (reverse)
	{
		ft_op_rrx(stack_a);
		ft_op_rrx(stack_b);
	}
	else
	{
		ft_op_rx(stack_a);
		ft_op_rx(stack_b);
	}
}
