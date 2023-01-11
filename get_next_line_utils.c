/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:19:14 by mpeterso          #+#    #+#             */
/*   Updated: 2023/01/11 13:27:31 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char    *ft_strdup(const char *s1)
{
        size_t  len;
        char    *dst;

        len = ft_strlen(s1) + 1;
        dst = malloc(len);
        if (dst == 0)
                return (NULL);
        ft_memcpy(dst, s1, len);
        return (dst);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *sub;
        size_t  i;
        size_t  j;

        if (ft_strlen(s) < start)
                return (ft_strdup(""));
        if (ft_strlen(&s[start]) < len)
                len = ft_strlen(&s[start]);
        sub = (char *)malloc(len + 1);
        if (!sub)
                return (0);
        i = start;
        j = 0;
        while (i < ft_strlen(s) && j < len)
        {
                sub[j] = s[i];
                j++;
                i++;
        }
        sub[j] = '\0';
        return (sub);
}*/

size_t  ft_strlen(char *s)
{
        size_t  i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

/*void    *ft_memcpy(void *dst, const void *src, size_t n)
{
        const char      *csrc;
        char            *cdst;

        if ((dst == src) || n == '\0')
                return (dst);
        if (dst == 0 && src == 0)
                return (0);
        csrc = (const char *)src;
        cdst = (char *)dst;
        while (n--)
                cdst[n] = csrc[n];
        return (cdst);
}*/

char    *ft_strjoin(char *line1, char *buff)
{
        char    *new_str;
        size_t  len;
        size_t  i;
        size_t  j;

        if (!line1)
        {
                line1 = (char *)malloc(sizeof(char) * 1);
                line1[0] = '\0';
        }
        if (!line1 || !buff)
                return (NULL);
        len = (ft_strlen(line1) + ft_strlen(buff) + 1);
        new_str = (char *)malloc(len * sizeof(char));
        if (new_str == NULL)
                return (NULL);
        i = -1;
        if (line1)
                while (line1[++i] != '\0')
                        new_str[i] = line1[i];
        j = 0;
        while (buff[j] != '\0')
                new_str[i++] = buff[j++];
        new_str[i++] = '\0';
        free(line1);
        return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
                s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	if (((unsigned char)c) == '\0')
		return ((char *)s);
	return (0);
}
