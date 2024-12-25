/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:43:37 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/25 17:08:41 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_printf.h"
#include "libft.h"

t_operations ft_get_type(char *line)
{
  char	*str;
	char	**commands;
  int i;

	//str = "sa\n:sb:pa:pb:ra:rb:rr:rra:rrb:rrr";
	str = "sa\n:sb\n:pa\n:pb\n:ra\n:rb\n:rr\n:rra\n:rrb\n:rrr";
	commands = ft_split(str, ':');
  if (!commands)
    return (0);
  i = 0;
  while (commands[i])
  {
    ft_printf("command: %s\n", commands[i]);
    ft_printf("line: %s\n", line);
    if (!ft_strncmp(line, commands[i], ft_strlen(line)))
    {
      free(commands);
      return (i + 1);
    }
    i++;
  }
  free(commands);
  return (0);
}
