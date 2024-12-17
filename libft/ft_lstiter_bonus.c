/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:06:28 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/09 16:32:22 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void print(void *content)
{
  printf("%s\n", (char *)content);
}

int	main(void)
{
  // test function
  t_list *list = ft_lstnew(ft_strdup("hello"));
  ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));
  ft_lstadd_back(&list, ft_lstnew("1337"));

  ft_lstiter(list, print);
  return (0);
}*/
