/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:59:24 by romoreir          #+#    #+#             */
/*   Updated: 2020/03/03 20:23:29 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

static void	free_and_null(char *line_read)
{
	free(line_read);
	line_read = NULL;
}

static void	print_line_details(char *line_read, int ret_gnl, int line_count)
{
	if (ret_gnl == 1)
		printf("%d: %s\n", line_count, line_read);
	else if (ret_gnl == 0)
		printf("---- EOF has reached ----\n");
	else if (ret_gnl == -1)
		printf("---- Error in gnl function ----\n");
	else
		printf("---- Unknown gnl return value ----\n");
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line_read;
	int		ret_gnl;
	size_t	line_count;
	int		file_index;


	file_index = 0;
	printf("\n---- GNL BONUS TEST ----\n\n");
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	if (argc == 1)
	{
		line_count = 0;
		while ((ret_gnl = get_next_line(0, &line_read)) > 0)
		{
			print_line_details(line_read, ret_gnl, ++line_count);
			free_and_null(line_read);
		}
	}
	else if (argc >= 2)
	{
		while (++file_index <= (argc - 1))
		{
			printf("\nFile -> %s\n", argv[file_index]);
			if ((fd = open(argv[file_index], O_RDONLY)) == -1)
			{
				printf("Error occurred in the read function.\n");
			exit(1);
			}
			line_count = 0;
			while ((ret_gnl = get_next_line(fd, &line_read)) > 0)
			{
				print_line_details(line_read, ret_gnl, ++line_count);
				free_and_null(line_read);
			}
			print_line_details(line_read, ret_gnl, ++line_count);
			if (close(fd) == -1)
			{
				free_and_null(line_read);
				printf("Error occured in the close function.\n");
				exit(1);
			}
			free_and_null(line_read);
		}
	}
	else
		printf("Invalid number of arguments.\n");
	return (0);
}
