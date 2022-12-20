#include "get_next_line.h"

static char	*ft_line(char *str)
{
	int	i; 
	char *line;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char *ft_after_line(char *str)
{
	int i;
	char *temp;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	temp = ft_strdup(&str[i + 1]);
	free(str);
	str = temp;
	return (str);
}

static char *ft_read(int fd, char *str)
{
	char *buff;
	int ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ret = 1;
	while (!ft_strchr(str , '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
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

	str = ft_read(fd, str);
	if (!str)
		return (NULL); 
	line = ft_line(str);
	str = ft_after_line(str);
	return (line);
}

int main (int argc, char **argv)
{
	int fd;
	char *line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";

	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
















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

