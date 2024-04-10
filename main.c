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

char	*get_next_line(int fd);

int main()
{
	int 	fd;
	char	*str;

	//fd  = 0;  					--test stdinput
	fd = open ("1.txt", O_RDONLY);
	//fd = open ("2.txt", O_RDONLY);
	//fd = open ("3.txt", O_RDONLY);		--for bonus tests
	//fd = open ("4.txt", O_RDONLY);
	str = get_next_line(fd);
	while(str != NULL)
	{
		printf("|%s|\n", str);
		free(str);
		str = get_next_line(fd);
	}
	//system("leaks a.out");
}
