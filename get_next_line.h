#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
void    *ft_memcpy(void *dst, const void *src, size_t n);
//char	*ft_line(char *str);
//char *ft_after_line(char *str);
//char *ft_read(int fd, char *str);
char *get_next_line(int fd);

#endif
