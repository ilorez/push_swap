/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:51:08 by znajdaou          #+#    #+#             */
/*   Updated: 2024/10/27 11:12:32 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	t;
	void	*ptr;

	if (size != 0 && (count > ((size_t)-1 / size)))
		return (NULL);
	t = count * size;
	ptr = malloc(t);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, t);
	return (ptr);
}

/*int main(int ac, char **av)
{
	int	*p;
	int	*p1;

  p = (int *)calloc(atoi(av[1]), atoi(av[2]));
  p1 = (int *)ft_calloc(atoi(av[1]), atoi(av[2]));
   if (!p)
  {
		printf("p is NULL");
}
if (!p1)
  {
		printf("p1 is NULL");
}
if (!p1 || !p)
	return (0);
  for (int i = 0; i < 10 ; i++)
  {
	printf("P:(%d:%d)\n",i, p[i]);
	printf("P1:(%d:%d)\n-------\n",i, p1[i]);
  }
  return (0);

}*/
