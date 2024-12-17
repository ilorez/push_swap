/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:12:37 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/09 16:32:02 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int main()
{
	t_list *lst = ft_lstnew("1");
	t_list *lst2 = ft_lstnew("2");
	t_list *lst3 = ft_lstnew("3");
	t_list *lst4 = ft_lstnew("4");
	t_list *lst5 = ft_lstnew("5");
	t_list *lst6 = ft_lstnew("6");
	t_list *lst7 = ft_lstnew("7");

	lst->next = lst2;
	lst2->next = lst3;
	lst3->next = lst4;
	lst4->next = lst5;
	lst5->next = lst6;
	lst6->next = lst7;

	t_list *last = ft_lstlast(lst);
	printf("%s\n", last->content);
}*/
