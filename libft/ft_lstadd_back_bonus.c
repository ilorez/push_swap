/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:24:41 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/09 16:17:56 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
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

	//t_list *new = ft_lstnew("8");
	ft_lstadd_back(&lst, NULL);
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}*/
