/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:05:47 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/09 16:32:31 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

/*void example_del(void *content)
{
  free(content);
}

int	main(void)
{
  t_list *list = ft_lstnew(ft_strdup("Hello"));
  printf("List content: %s\n", (char *)list->content);
  ft_lstdelone(list, example_del);

  printf("ptr %p", list);
  list = NULL;
  printf("ptr %p", list);
  // test if list is deleted
  if (list && list->content)
  {
	printf("List is not deleted\n");
	printf("List content: %s\n", (char *)list->content);
  }
  else
	printf("List is deleted\n");

  return (0);
}*/
