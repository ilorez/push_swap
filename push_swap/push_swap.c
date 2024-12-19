/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:51:01 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 15:05:53 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/t_bool.h"
#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "push_swap.h"

t_bool	ft_is_valid(char *str)
{
  if (*str == '+' || *str == '-')
    str++;
  if(!*str)
    return (false);
	while (*str)
  {
		if (!ft_isdigit(*str))
			return (false);
    str++;
  }
	return (true);
}

t_bool	ft_create_stack(int ac, char **av, t_list **stack_a)
{
	long long	num;
	char		**str_nums;
	t_list		*new_num;
  int *int_num;
  int i;

	while (--ac > 0)
	{
		str_nums = ft_split(av[ac], ' ');
		if (!str_nums)
			return (false);

    i = 0;
		while (str_nums[i])
		{
			if (!ft_is_valid(str_nums[i]))
      {
        ft_printf("Error\nnot all digits\n");
				return ((t_bool)ft_free_str_lst(str_nums));
      }
			num = ft_atol(str_nums[i++]);
			if (num > INT_MAX || num < INT_MIN)
			{
				ft_printf("Error\nnot valid number\n \
          found a number out of INT range\n");
				return ((t_bool)ft_free_str_lst(str_nums));
			}
      int_num = malloc(sizeof(int));
      *int_num = (int)num;
			new_num = ft_lstnew((int_num));
			if (!new_num)
			{
				ft_printf("Error\nnew_num desn't allocated correctly!");
				return ((t_bool)ft_free_str_lst(str_nums));
			}
			ft_lstadd_back(&(*stack_a), new_num);
		}
		ft_free_str_lst(str_nums);
	}
	return (true);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;

	stack_a = NULL;
	if (ac == 1)
		ft_printf("Error\nNo numbers passed!:[\nto pass argument use for example \
%s 1 2 3 4 5", av[0]);
	if (!ft_create_stack(ac, av, &stack_a))
  {
    ft_printf("stack doesn't created\n");
		ft_lstclear(&stack_a, free);
    return 0;
  }
	ft_print_stack(stack_a);
  ft_printf("running SA on stack a\n");
	ft_print_stack(stack_a);
	//ft_lstclear(&stack_a, free);
}
