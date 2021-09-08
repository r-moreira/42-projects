/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	line_len(const char *str)
{
	size_t	nbytes;

	nbytes = 0;
	while (str[nbytes] != '\n')
		nbytes++;
	return (nbytes);
}

static size_t	make_line(int nbytes, char **line, char **str)
{
	char	*temp;
	size_t	start;
	size_t	len;

	if (nbytes != 0)
	{
		*line = ft_substr(*str, 0, line_len(*str));
		temp = *str;
		start = line_len(temp) + 1;
		len = ft_strlen(temp) - line_len(temp);
		*str = ft_substr(temp, start, len);
		free(temp);
		temp = NULL;
		return (1);
	}
	else
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
}

static size_t	read_file(int fd, char *buffer, char **str)
{
	size_t	nbytes;
	char	*temp;

	nbytes = 1;
	while (nbytes)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		buffer[nbytes] = '\0';
		temp = *str;
		*str = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(*str, '\n'))
			break ;
	}
	return (nbytes);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*str;
	size_t		nbytes;
	size_t		gnl_ret;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!line || read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1 || fd < 0)
	{
		free(buffer);
		buffer = NULL;
		return (-1);
	}
	if (!str)
		str = ft_strdup("");
	if (!ft_strchr(str, '\n'))
		nbytes = read_file(fd, buffer, &str);
	else
		nbytes = line_len(str) + 1;
	free(buffer);
	buffer = NULL;
	gnl_ret = make_line(nbytes, line, &str);
	return (gnl_ret);
}
