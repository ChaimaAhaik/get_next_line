/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:02:33 by cahaik            #+#    #+#             */
/*   Updated: 2024/04/20 10:45:52 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char *get_next_line(int fd);
ssize_t ft_strlen(char *str);
ssize_t pos_index(char *buffer, int c);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *str);
char *our_line(char *rmd);
char *holding(int fd, char *rmd);
void ft_free(char **str);

#endif