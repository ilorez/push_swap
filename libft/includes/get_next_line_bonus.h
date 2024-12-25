/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:00:55 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/12 15:19:20 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
//# include <stdio.h>
//# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strdup(const char *s1);
char	*ft_gnl_sublen(char const *s, size_t len);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char const *s1, char const *s2);

#endif
