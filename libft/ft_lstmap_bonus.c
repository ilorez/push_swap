/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:35:16 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/11 12:09:49 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r_lst;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	r_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&r_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&r_lst, node);
		lst = lst->next;
	}
	return (r_lst);
}

/*void example_del(void *content)
{
  free(content);
}

void	example_putstr_fd(void *content)
{
  ft_putstr_fd(content, 1);
}

int	main(void)
{
  t_list *lst;
  t_list *r_lst;
  lst = ft_lstnew("Hello");
  ft_lstadd_back(&lst, ft_lstnew("World"));
  r_lst = ft_lstmap(lst, (void *)(&ft_strdup), example_del);
  ft_lstiter(r_lst, &example_putstr_fd);
  ft_lstclear(&r_lst, &example_del);
  return (0);
}*/
