/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:42:46 by cahaik            #+#    #+#             */
/*   Updated: 2024/04/20 15:31:10 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_read_line(int fd, char **reminder)
{
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(*reminder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(*reminder);
			reminder = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		*reminder = ft_strjoin(*reminder, buffer);
	}
	free(buffer);
	return (*reminder);
}

char	*our_line(char *start)
{
	int		i;
	char	*line;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*tmp;
	char		*line;
	char		*search;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(reminder), reminder = NULL, NULL);
	my_read_line(fd, &reminder);
	search = ft_strchr(reminder, '\n');
	if (reminder && !search)
	{
		tmp = ft_strdup(reminder);
		free(reminder);
		return (reminder = NULL, tmp);
	}
	else if (reminder && search)
	{
		tmp = reminder;
		line = our_line(reminder);
		reminder = ft_strdup(search + 1);
		return (free(tmp), line);
	}
	return (NULL);
}
