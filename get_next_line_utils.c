#include "get_next_line.h"

char    *ft_strdup(const char *s1)
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

/*char    *ft_substr(char const *s, unsigned int start, size_t len)
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

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
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
}

char    *ft_strjoin(char *s1, char *s2)
{
        char    *new_str;
        size_t  len;
        size_t  i;
        size_t  j;

        if (!s1)
        {
                s1 = (char *)malloc(sizeof(char) * 1);
                s1[0] = '\0';
        }
        len = (ft_strlen(s1) + ft_strlen(s2) + 1);
        new_str = (char *)malloc(len * sizeof(char));
        if (new_str == 0)
                return (NULL);
        i = -1;
        while (s1[++i] != '\0')
                new_str[i] = s1[i];
        j = 0;
        while (s2[j] != '\0')
        {
                new_str[i++] = s2[j++];
        }
        new_str[i] = '\0';
        free(s1);
        return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (((unsigned char)c) == '\0')
		return ((char *)s + i);
	return (0);
}
