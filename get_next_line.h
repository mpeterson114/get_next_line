/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:19:08 by mpeterso          #+#    #+#             */
/*   Updated: 2023/01/11 13:26:34 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//char    *ft_strdup(const char *s1);
size_t  ft_strlen(char *s);
char    *ft_strjoin(char *line1, char *buff);
//void    *ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
//char	*ft_line(char *str);
//char *ft_after_line(char *str);
//char *ft_read(int fd, char *str);
char	*ft_line(char *str);
char *ft_after_line(char *str);
char *ft_read(int fd, char *str);
char *get_next_line(int fd);

#endif
