/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:43:27 by znajdaou          #+#    #+#             */
/*   Updated: 2024/10/27 18:57:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	size;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (ft_strdup(""));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(size);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, size);
	ft_strlcat(dst, s2, size);
	return (dst);
}

/*int main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%s\n", ft_strjoin(av[1], av[2]));
		printf("%s\n", ft_strjoin(av[1], NULL));
		printf("%s\n", ft_strjoin(NULL, av[2]));
		printf("%s\n", ft_strjoin(NULL, NULL));
		// strjoin1
		printf("strjoin1-----\n:%s\n", ft_strjoin1(av[1], av[2]));
		printf("%s\n", ft_strjoin1(av[1], NULL));
		printf("%s\n", ft_strjoin1(NULL, av[2]));
		printf("%s\n", ft_strjoin1(NULL, NULL));


	}
	return (0);
}*/
