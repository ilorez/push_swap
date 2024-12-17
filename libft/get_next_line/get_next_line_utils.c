/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:00:38 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/16 17:12:59 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* ft_gnl_strdup
 * this function is used to duplicate a string
 * @param s1: the string that we will duplicate
 * @return: the address of the duplicated string
 * @return: NULL if the string is empty
 **/
char	*ft_gnl_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(ft_gnl_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* ft_gnl_sublen
 * this function is used to duplicate a substring
 * @param s: the string that we will duplicate
 * @param len: the length of the substring
 * @return: the address of the duplicated substring
 * @return: NULL if the string is empty
 **/
char	*ft_gnl_sublen(char const *s, size_t len)
{
	char	*ss;

	ss = (char *)malloc(len * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	ss[len] = '\0';
	while (len--)
		ss[len] = s[len];
	return (ss);
}

/* ft_gnl_strchr
 * this function is used to search for a character in a string
 * @param s: the string that we will search in
 * @param c: the character that we will search for
 * @return: the address of the first occurence of the character in the string
 * @return: NULL if the character is not found
 * #Note: this function is static and can be used only in this file
 **/
char	*ft_gnl_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] != (char)c)
		return (NULL);
	return ((char *)(&(s[i])));
}

/* ft_gnl_strjoin
 * this function is used to concatenate two strings
 * @param s1: the first string
 * @param s2: the second string
 * @return: the address of the concatenated string
 * @return: s1 if s2 is NULL and vice versa || if both are NULL return ""

	* @note: the funciton always return a new allocated string 
  * or null that can always be freed
 **/
char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	size;

	i = 0;
	if (s1 && !s2)
		return (ft_gnl_strdup(s1));
	if (!s1 && s2)
	{
		return (ft_gnl_strdup(s2));
	}
	if (!s1 && !s2)
		return (ft_gnl_strdup(""));
	size = ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1;
	dst = malloc(size);
	if (!dst)
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *s1++;
	while (*s2)
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}
