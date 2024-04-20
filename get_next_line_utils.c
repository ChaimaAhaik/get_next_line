/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:02:52 by cahaik            #+#    #+#             */
/*   Updated: 2024/04/20 10:52:11 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
ssize_t pos_index(char *buffer, int c)
{
	ssize_t i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == (char)c)
			return (i);
			i++;
	}
	return (-1);
}
char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *ptr;
	
	i = 0;
	j = 0;
	// if (!s1 && !s2)
	// 	return (NULL);
	if (!s2)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		ptr[i++] = s2[j++];
	}
	ptr[i] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (ptr);
}

char *ft_strdup(char *str)
{
	int i;
	char *ptr;

	i = 0;
	// if (!str)
	// 	return (NULL);
	ptr = malloc(ft_strlen(str) + 1);
	if (!ptr)
	{
		return(NULL);
	}
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
	
}
