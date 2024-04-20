/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:01:08 by cahaik            #+#    #+#             */
/*   Updated: 2024/04/20 10:55:17 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

// char *holding(int fd, char *rmd)
// {
// 	char *buffer;
// 	ssize_t bytes_read;
	
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while (pos_index(rmd, '\n') == -1)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if(bytes_read < 0)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		if (bytes_read == 0)
// 		 break;
// 		buffer[bytes_read] = '\0';
// 		rmd = ft_strjoin(rmd, buffer);
// 	}
// 	free(buffer);
// 	return (rmd);
// }

// char *our_line(char *rmd)
// {
// 	int i;
// 	int index;
// 	char *buffer;

// 	i = 0;
// 	index = 0;
// 	while (rmd[index] != '\n' && rmd[index] != '\0')
// 		index++;
// 	buffer = malloc(index + 2);
// 	if (!buffer)
// 			return (NULL);
// 	while (i < index)
// 	{
// 		buffer[i] = rmd[i];
// 		i++;
// 	}
// 	buffer[i] = '\n';
// 	buffer[++i] = '\0';
// 	return (buffer);
// }
// // static char	*ft_substr(char *s, unsigned int start, size_t len)
// // {
// // 	size_t	i;
// // 	char	*ptr;

// // 	i = 0;
// // 	if (!s)
// // 		return (NULL);
// // 	if (start >= (unsigned int)ft_strlen(s) || len == 0)
// // 		return (ft_strdup(""));
// // 	if (len >(size_t )(ft_strlen(s) - start))
// // 		return (ft_strdup(s + start));
// // 	ptr = (char *)malloc(sizeof(char) * (len + 1));
// // 	if (!ptr)
// // 		return (NULL);
// // 	while (i < len && s[start] != '\0')
// // 	{
// // 		ptr[i] = s[start];
// // 		i++;
// // 		start++;
// // 	}
// // 	ptr[i] = '\0';
// // 	return (ptr);
// // }

// char *get_next_line(int fd)
// {
// 	char *buffer;
// 	char *line;
// 	static char *rmd;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0 ,0) == -1)
// 	{
// 		free(rmd);
// 		rmd = NULL;
// 		return (NULL);
// 	}
// 	buffer = holding(fd,rmd);
// 	if (pos_index(buffer, '\n') == -1)
// 	{
// 		if (!buffer || *buffer == '\0')
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		return (buffer);
// 	}
// 	line = our_line(buffer);
// 	printf("line [%s]", line);
// 	// line = ft_substr(buffer, 0,  pos_index(buffer, '\n'));
// 	rmd = ft_strdup(buffer + pos_index(buffer, '\n'));
// 	free(buffer);
// 	return (line);
// }


/* SECOND TRY */
// void ft_free(char **str)
// {
// 	free(*str);
// 	*str = NULL;
// }
// char *holding(int fd, char *reminder)
// {
// 	ssize_t bytes_read;
// 	char *buffer;
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while(pos_index(reminder, '\n') == -1)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read == 0)
// 			break;
// 		buffer[bytes_read] = '\0';
// 		reminder = ft_strjoin(reminder, buffer);
// 	}
// 	ft_free(&buffer);

// 	// printf("khouna %s", reminder);
// 	return (reminder);
// }
// char *our_line(char *buffer)
// {
// 	ssize_t i;
// 	ssize_t iter;

// 	iter = 0;
// 	char *line;
// 	i = pos_index(buffer, '\n') + 1;
// 	// printf("%zd\n", i);
// 	line = malloc(i + 1);
// 	if (!line)
// 		return(NULL);
// 	while (iter < i)
// 	{
// 		line[iter] = buffer[iter];
// 		iter++;
// 	}
// 	line[iter] = '\0';
// 	return (line);
// }
// char *get_next_line(int fd)
// {
// 	static char *reminder;
// 	char *buffer;
// 	char *line;
// 	int position;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
// 	{
// 		ft_free(&reminder);
// 		reminder = NULL;
// 		return (NULL);
// 	}
// 	buffer = holding(fd, reminder);
// 	if (pos_index(buffer, '\n') == -1)
// 	{
// 		if (reminder)
// 		{
// 			ft_free(&reminder);
// 			reminder = NULL;
// 		}
// 		if (!buffer || !*buffer)
// 		{
// 			ft_free(&buffer);
// 			return (NULL);
// 		}
// 		return (buffer);
// 	}

// 	line = our_line(buffer);
// 	if (!line)
// 	{
// 		ft_free(&buffer);
// 		if (reminder)
// 			ft_free(&reminder);
// 		return (NULL);
// 	}

// 	position = pos_index(buffer, '\n');
// 	reminder = ft_strdup(buffer + (position + 1));
// 	if (!reminder)
// 	{
// 		// ft_free(&reminder);
// 		ft_free(&buffer);
// 		return (NULL);
// 	}
// 	if (reminder && !reminder[0])
// 	{
// 		ft_free(&reminder);
// 		reminder = NULL;
// 	}
// 	ft_free(&buffer);
// 	return(line);
// }



/*  TRY: 3 */

// void ft_free(char **str)
// {
// 	free(*str);
// 	*str = NULL;
// }
// char *holding(int fd, char *reminder)
// {
// 	ssize_t bytes_read;
// 	char *buffer;
	
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while(pos_index(reminder, '\n') == -1)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read == 0)
// 			break;
// 		buffer[bytes_read] = '\0';
// 		reminder = ft_strjoin(reminder, buffer);
// 	}
// 	ft_free(&buffer);

// 	// printf("khouna %s", reminder);
// 	return (reminder);
// }
// char *our_line(char *buffer)
// {
// 	ssize_t i;
// 	ssize_t iter;

// 	iter = 0;
// 	char *line;
// 	i = pos_index(buffer, '\n') + 1;
// 	// printf("%zd\n", i);
// 	line = malloc(i + 1);
// 	if (!line)
// 		return(NULL);
// 	while (iter < i)
// 	{
// 		line[iter] = buffer[iter];
// 		iter++;
// 	}
// 	line[iter] = '\0';
// 	return (line);
// }
// char *get_next_line(int fd)
// {
// 	static char *reminder;
// 	char *buffer;
// 	char *line;
// 	int position;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
// 	{
// 		ft_free(&reminder);
// 		reminder = NULL;
// 		return (NULL);
// 	}
// 	buffer = holding(fd, reminder);
// 	if (pos_index(buffer, '\n') == -1)
// 	{
// 		if (reminder)
// 		{
// 			ft_free(&reminder);
// 			reminder = NULL;
// 		}
// 		if (!buffer || !*buffer)
// 		{
// 			// ft_free(&buffer);
// 			return (NULL);
// 		}
// 		return (buffer);
// 	}

// 	line = our_line(buffer);
// 	if (!line)
// 	{
// 		ft_free(&buffer);
// 		if (reminder)
// 			ft_free(&reminder);
// 		return (NULL);
// 	}

// 	position = pos_index(buffer, '\n');
// 	reminder = ft_strdup(buffer + (position + 1));
// 	if (!reminder)
// 	{
// 		// ft_free(&reminder);
// 		ft_free(&buffer);
// 		return (NULL);
// 	}
// 	if (reminder && !reminder[0])
// 	{
// 		ft_free(&reminder);
// 		reminder = NULL;
// 	}
// 	ft_free(&buffer);
// 	return(line);
// }


// debugging

// void ft_free(char **str)
// {
// 		free(*str);
// 	*str = NULL;
// }

// char *holding(int fd, char *reminder)
// {
// 	ssize_t bytes_read;
// 	char *buffer;
	
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while(pos_index(reminder, '\n') == -1)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read == 0)
// 			break;
// 		buffer[bytes_read] = '\0';
// 		reminder = ft_strjoin(reminder, buffer);

// 	}
// 	// if (buffer)
// 	// 	ft_free(&buffer);
// 	// char *test;
// 	// if (*reminder != NULL)
// 	// {
// 	// 	test = ft_strdup(*reminder);
// 	// }
// 	// else 
// 	// 	test = NULL;
// 	return (reminder);
// }
// char *our_line(char *buffer)
// {
// 	ssize_t i;
// 	ssize_t iter;

// 	iter = 0;
// 	char *line;
// 	i = pos_index(buffer, '\n') + 1;
// 	line = malloc(i + 1);
// 	if (!line)
// 		return(NULL);
// 	while (iter < i)
// 	{
// 		line[iter] = buffer[iter];
// 		iter++;
// 	}
// 	line[iter] = '\0';
// 	return (line);
// }
// char *get_next_line(int fd)
// {
// 	static char *reminder;
// 	char *buffer;
// 	char *line;
// 	int position;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
// 	{
// 		ft_free(&reminder);
// 		reminder = NULL;
// 		return (NULL);
// 	}
// 	buffer = holding(fd, reminder);
// 	if (pos_index(buffer, '\n') == -1)
// 	{
// 		if (reminder)
// 		{
// 			ft_free(&reminder);
// 			reminder = NULL;
// 		}
// 		if (!buffer || !*buffer)
// 		{
// 			ft_free(&buffer);
// 			return (NULL);
// 		}
// 		return (buffer);
// 	}

// 	line = our_line(buffer);
// 	if (!line)
// 	{
// 		ft_free(&buffer);
// 		if (reminder)
// 			ft_free(&reminder);
// 		return (NULL);
// 	}

// 	position = pos_index(buffer, '\n');
// 	reminder = ft_strdup(buffer + (position + 1));
// 	if (!reminder)
// 	{
// 		ft_free(&reminder);
// 		ft_free(&buffer);
// 		return (NULL);
// 	}
// 	if (reminder && !reminder[0])
// 	{
// 		ft_free(&reminder);
// 		reminder = NULL;
// 	}
// 	ft_free(&buffer);
// 	return(line);
// }







// void ft_free(char **str)
// {
// 	free(*str);
// 	*str = NULL;
// }
// char *holding(int fd, char *reminder)
// {
// 	ssize_t bytes_read;
// 	char *buffer;
	
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	while(pos_index(reminder, '\n') == -1)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read == 0)
// 			break;
// 		buffer[bytes_read] = '\0';
// 		reminder = ft_strjoin(reminder, buffer);
// 	}
// 	free(buffer);
// 	return (reminder);
// }
// char *our_line(char *buffer)
// {
// 	ssize_t i;
// 	ssize_t iter;

// 	iter = 0;
// 	char *line;
// 	i = pos_index(buffer, '\n') + 1;
// 	line = malloc(i + 1);
// 	if (!line)
// 		return(NULL);
// 	while (iter < i)
// 	{
// 		line[iter] = buffer[iter];
// 		iter++;
// 	}
// 	line[iter] = '\0';
// 	return (line);
// }
// char *get_next_line(int fd)
// {
// 	static char *reminder;
// 	char *buffer;
// 	char *line;
	
// 	int position;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
// 	{
// 		ft_free(&reminder);
// 		return (NULL);
// 	}
// 	buffer = holding(fd, reminder);
// 	if (pos_index(buffer, '\n') == -1)
// 	{
// 		if (reminder && !reminder[0])
// 		{
// 			ft_free(&reminder);
// 		}
// 		if (reminder)
// 			ft_free(&reminder);
// 		if (!buffer || !*buffer)
// 		{
// 			ft_free(&buffer); 
// 			return (NULL);
// 		}
// 		line = buffer;
// 		buffer = NULL;
// 		return (line);
// 	}
// 	line = our_line(buffer);
// 	if (!line)
// 	{
// 		free(buffer);
// 		if (reminder)
// 			ft_free(&reminder);
// 		return (NULL);
// 	}

// 	position = pos_index(buffer, '\n');
// 	reminder = ft_strdup(buffer + (position + 1));
// 	if (!reminder)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	if (reminder && !reminder[0])
// 	{
// 		ft_free(&reminder);
// 	}
// 	if (buffer)
// 		free(buffer);
// 	return(line);
// }


// akhir try



void ft_free(char **str)
{
	free(*str);
	*str = NULL;
}
char *holding(int fd, char *reminder)
{
	ssize_t bytes_read;
	char *buffer;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while(pos_index(reminder, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		reminder = ft_strjoin(reminder, buffer);
	}
	free(buffer);
	return (reminder);
}
char *our_line(char *buffer)
{
	ssize_t i;
	ssize_t iter;

	iter = 0;
	char *line;
	i = pos_index(buffer, '\n') + 1;
	line = malloc(i + 1);
	if (!line)
		return(NULL);
	while (iter < i)
	{
		line[iter] = buffer[iter];
		iter++;
	}
	line[iter] = '\0';
	return (line);
}
char *get_next_line(int fd)
{
	static char *reminder;
	char *buffer;
	char *line;
	
	int position;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		ft_free(&reminder);
		return (NULL);
	}
	buffer = holding(fd, reminder);
	if (pos_index(buffer, '\n') == -1)
	{
		if (reminder && !reminder[0])
		{
			ft_free(&reminder);
		}
		if (reminder)
			ft_free(&reminder);
		if (!buffer || !*buffer)
		{
			ft_free(&buffer); 
			return (NULL);
		}
		line = buffer;
		buffer = NULL;
		return (line);
	}
	line = our_line(buffer);
	if (!line)
	{
		free(buffer);
		if (reminder)
			ft_free(&reminder);
		return (NULL);
	}

	position = pos_index(buffer, '\n');
	reminder = ft_strdup(buffer + (position + 1));
	// if (!reminder)
	// {
	// 	free(buffer);
	// 	return (NULL);
	// }
	if (reminder && !reminder[0])
	{
		ft_free(&reminder);
	}
	if (buffer)
		free(buffer);
	return(line);
}
