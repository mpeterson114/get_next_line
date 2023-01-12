#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

size_t  ft_strlen(char *s);
char    *ft_strjoin(char *line1, char *buff);
char	*ft_strchr(char *s, int c);
char	*ft_line(char *str);
char *ft_after_line(char *str);
char *ft_read(int fd, char *str);
char *get_next_line(int fd);

#endif
