/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:43:37 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/26 10:48:30 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"
#include "libft.h"

t_operations	ft_get_type(char *line)
{
	char	*str;
	char	**commands;
	int		i;

	str = "sa\n:sb\n:pa\n:pb\n:ra\n:rb\n:rr\n:rra\n:rrb\n:rrr\n";
	commands = ft_split(str, ':');
	if (!commands)
		return (0);
	i = 0;
	while (commands[i])
	{
		if (!ft_strncmp(line, commands[i], ft_strlen(line)))
		{
			ft_free_str_lst(commands);
			return (i + 1);
		}
		i++;
	}
	ft_free_str_lst(commands);
	return (0);
}
