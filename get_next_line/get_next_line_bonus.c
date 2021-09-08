/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
**	Description and objetive:
**		This is a simple function returns the number of bytes to next "\n"
**	Parameter:
**		The string that was read from the file
*/

static size_t	line_len(const char *str)
{
	size_t	nbytes;

	nbytes = 0;
	while (str[nbytes] != '\n')
		nbytes++;
	return (nbytes);
}

/*
**	Description:
**		This is an auxiliary function to make the line.
**	Parameters:
**		#1 Number of bytes.
**		#2 Variable to store the value of what has been read.
**		#3 The string that will be divided into lines.
**	Objectives:
**		Check if the nbytes is different from 0 (if bytes == 0 means that \
**		there is nothing between the beginning and the end of the str, in this
**		case is the EOF)
**		Save in the variable line the beginning of the string up to "\n"
**		Remove the content of str which has already been saved in the \
**		variable line and returns 1 to get_next_file function.
**		If nbytes == 0 means that is EOF, so the function needs to \
**		save the content of str variable in line variable, and return 0 to \
**		the get_next_file function.
**		Free str and temp variables.
*/

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

/*
**	Description:
**		This is an auxiliary function to read the file.
**	Parameters:
**		#1 File descriptor.
**		#2 Buffer allocated in the get_next_line function.
**		#3 Static variable address
**	Objectives:
**		Call the read function to read the file, using the BUFFFER_SIZE macro.
**		Store in the buffer, placing the "\n" at the end.
**		With a temporary variable get the str content to avoid memory leaks.
**		Place the buffer content in the static variable.
**		Free the useless temp variable.
**		If str has "\n" we need break to avoid nbytes be equals 0, this /
**		variable will tell future tests if a line exist or not.
*/

static size_t	read_file(int fd, char *buffer, char **str)
{
	size_t	nbytes;
	char	*temp;

	while ((nbytes = read(fd, buffer, BUFFER_SIZE)))
	{
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

/*
**	Description:
**		This is the core function of the program.
**	Parameters:
**		#1 A file descriptor for reading
**		#2 The value of what has been read.
**	Objectives:
**		Check the possible errors one by one.
**			if buffer can't be allocated
**			if line exists
**			if read function works
**			if buffer and fd is valid
**		Start the static variáble.
**		Call auxiliary functions when needed
**			if there is no "\n" in the static variable, we need to read \
**			the file, calling the read_file function.
**			else we get the number of bytes until the next"\n", calling \
**			the line_len function.
**			With the number of bytes, call the make_line function and get \
**			its return.
**		Free buffer variable before return.
**		Return values:
**			-1 -> for error.
**			1 -> when a line has been read.
**			0 -> when EOF has been reached.
*/

int				get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*str[OPEN_MAX];
	size_t		nbytes;
	size_t		gnl_ret;

	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!line || read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1 || fd < 0)
	{
		free(buffer);
		buffer = NULL;
		return (-1);
	}
	if (!str[fd])
		str[fd] = ft_strdup("");
	if (!ft_strchr(str[fd], '\n'))
		nbytes = read_file(fd, buffer, &str[fd]);
	else
		nbytes = line_len(str[fd]) + 1;
	free(buffer);
	buffer = NULL;
	gnl_ret = make_line(nbytes, line, &str[fd]);
	return (gnl_ret);
}
