/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:16:25 by mpeterso          #+#    #+#             */
/*   Updated: 2023/02/12 14:16:28 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

int main(int argc, char **argv)
{
	int 	fd;
	char	*line;

	//fd  = 0;  					--test stdinput
	fd = open(argv[1], O_RDONLY); 
	line = "";
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	fd = close(fd);
	return (0);
}
