/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:15:44 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/18 16:58:45 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long  _ft_max_as_signe(int signe)
{
  if (signe == 1)
    return (LLONG_MAX);
  return (LLONG_MIN);
}

long long	ft_atol(const char *nptr)
{
	size_t				i;
	int					signe;
	unsigned long long int	re;

	i = 0;
	signe = 1;
	re = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			signe = -1;
	while (ft_isdigit(nptr[i]))
  {
    if (re > (LLONG_MAX - (nptr[i] - 48)) / 10)
			return (_ft_max_as_signe(signe));
		re = re * 10 + (nptr[i++] - 48);
  }
	return (re * signe);
}


int main()
{

  // test  long long limits
  


}
