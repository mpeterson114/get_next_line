/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:19:19 by mpeterso          #+#    #+#             */
/*   Updated: 2023/01/11 13:28:42 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *str)
{
	int	i; 
	char *line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;	
	}
	line[i] = '\0';
	return (line);
}

char *ft_after_line(char *str)
{
	int i;
	int j;
	char *temp;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!temp)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
	/*while (str[i] != '\n' && str[i])
		i++;
	temp = ft_strdup(&str[i + 1]);
	free(str);
	str = temp;
	return (str);*/
}

/*int	ft_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}*/

char *ft_read(int fd, char *str)
{
	char *buff;
	int ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (!ft_strchr(str, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

	/*ret = read(fd, buff, BUFFER_SIZE);
	if (ret < 0)
		return (NULL);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		temp = ft_strjoin(str, buff);
		free(str);
		str = temp; 
		if (*str == '\n')
			break ;
	}
	free(buff);
	return (str);
}*/

char *get_next_line(int fd)
{
	static char *str;
	char *line; 

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL); 
	line = ft_line(str);
	str = ft_after_line(str);
	return (line);
}

/*int main (void)
{
	int fd;
	char *line;

	fd = open("abc.txt", O_RDONLY);

	//test STDIN
	//fd = 0;

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	//line = get_next_line(fd);
	//printf("%s", line);
	close(fd);
	return (0);
}*/
















/*static char *ft_output(int fd, int ret, char **str, char **line)
{
	if (ret < 0)
		return (NULL);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		strclear(&(str[fd]));
		return (NULL);
	}
	else
		return (ft_find_line(fd, str, line));
}*/

