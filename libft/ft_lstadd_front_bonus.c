/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:06:20 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/19 09:21:25 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		*lst = new;
	else if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int main(int ac, char **av)
{
	t_list *first;
	t_list *second;

	if ( ac >= 3)
	{
		first = ft_lstnew(av[1]);
		second = ft_lstnew(av[2]);
		ft_lstadd_front(&second, first);
		printf("first item:[%s]\nsecond item:[%s]\n", second->content,
			second->next->content);
	}
}*/
