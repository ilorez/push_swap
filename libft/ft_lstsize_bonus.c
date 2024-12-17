/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:43:21 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/09 16:31:43 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/*int	main(int ac, char **av)
{
	t_list	*first;

	if (ac >= 4)
	{
		first = ft_lstnew(av[1]);
		first->next = ft_lstnew(av[2]);
		first->next->next = ft_lstnew(av[3]);
		first->next->next->next = ft_lstnew(av[3]);
		printf("size of the list: %d\n", ft_lstsize(first));
	}
}*/
