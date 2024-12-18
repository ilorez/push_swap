/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:36:50 by znajdaou          #+#    #+#             */
/*   Updated: 2024/12/18 09:36:55 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_str_lst(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}
/*
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>




int	main(void)
{
	char	**strs;

	// Allocate memory for the array of strings
	strs = malloc(4 * sizeof(char *));
	if (!strs)
	{
		perror("Failed to allocate memory for strs");
		return (1);
	}
	// Allocate memory for each string and initialize them
	strs[0] = malloc(10 * sizeof(char));
	strs[1] = malloc(20 * sizeof(char));
	strs[2] = malloc(30 * sizeof(char));
	strs[3] = NULL; // NULL terminator for the array
	if (!strs[0] || !strs[1] || !strs[2])
	{
		perror("Failed to allocate memory for strings");
		ft_free_str_lst(strs);
		return (1);
	}
	// Fill the strings with some values
	snprintf(strs[0], 10, "Hello");
	snprintf(strs[1], 20, "World");
	snprintf(strs[2], 30, "Test");
	// Print the strings
	printf("Before freeing:\n");
	for (int i = 0; strs[i]; i++)
		printf("strs[%d]: %s\n", i, strs[i]);
	// Free the memory and set the pointer to NULL
	strs = ft_free_str_lst(strs);
	// Verify if the pointer is NULL
	if (strs == NULL)
		printf("Memory successfully freed and pointer set to NULL.\n");
	else
		printf("Pointer is not NULL after freeing.\n");
	return (0);
}
*/
