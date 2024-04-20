// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/17 19:54:13 by cahaik            #+#    #+#             */
// /*   Updated: 2024/04/18 10:13:00 by cahaik           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *line;
		// printf("LINE %d: %s",fd, line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s",line);
		printf("our adress------------>>%p\n", &line);
		// sleep(1);
		system("leaks a.out");
	}
// printf("%s",(line = get_next_line(fd)));
// printf("%s",(line = get_next_line(fd)));
// printf("%s",(line = get_next_line(fd)));


	// line = get_next_line(fd);
	// printf("%s",line);
	// free(line);
	// line = get_next_line(fd);
	// printf("%s",line);
	// free(line);
	close(fd);
	return(0);
}