/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:23:41 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/03 15:59:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*ss;

	if (!s)
		return (NULL);
	if (start >= (size_t)ft_strlen(s))
	{
		ss = (char *)(malloc(sizeof(char)));
		if (!ss)
			return (NULL);
		ss[0] = '\0';
		return (ss);
	}
	size = 0;
	size = ft_strlen((char *)(s + start));
	if (size > len)
		size = len;
	ss = (char *)malloc(size * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	ft_strlcpy(ss, (char *)(s + start), size + 1);
	return (ss);
}

/*int main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%s\n", ft_substr(av[1], atoi(av[2]), atoi(av[3])));
		// original function
		// printf("%s\n", substr(av[1], atoi(av[2]), atoi(av[3])));
	}
	return (0);
}*/
