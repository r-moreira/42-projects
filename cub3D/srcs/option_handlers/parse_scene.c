/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_bool	is_all_configs_parsed(t_game *opts)
{
	if (opts->floor.r != UNDEFINED
		&& opts->floor.g != UNDEFINED
		&& opts->floor.b != UNDEFINED
		&& opts->ceil.r != UNDEFINED
		&& opts->ceil.g != UNDEFINED
		&& opts->ceil.b != UNDEFINED
		&& opts->tex.path.no
		&& opts->tex.path.so
		&& opts->tex.path.we
		&& opts->tex.path.ea
		&& opts->tex.path.s)
	{
		opts->utils.is_all_configs_parsed = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

static void	parse_scene_line(t_game *opts, char *line)
{
	if (is_all_configs_parsed(opts))
		create_map_buffer(opts, line);
	else
	{
		while (ft_isspace(*line))
			line++;
		if (*line == 'F' || *line == 'C')
			get_rgb(opts, line);
		else if (line[0] == 'N' && line[1] == 'O')
			get_path(opts, line, "NO");
		else if (line[0] == 'S' && line[1] == 'O')
			get_path(opts, line, "SO");
		else if (line[0] == 'W' && line[1] == 'E')
			get_path(opts, line, "WE");
		else if (line[0] == 'E' && line[1] == 'A')
			get_path(opts, line, "EA");
		else if (line[0] == 'S')
			get_path(opts, line, "S");
	}
}

void	parse_scene(char *path, t_game *opts)
{
	int		fd;
	char	*line_read;
	int		ret_gnl;

	fd = open(path, O_RDONLY);
	if (fd == ERROR)
		exit_failure("Error in the read function", opts);
	ret_gnl = TRUE;
	line_read = NULL;
	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line_read);
		if (ret_gnl == TRUE)
		{
			parse_scene_line(opts, line_read);
			free_and_null(line_read);
		}
	}
	if (close(fd) == ERROR)
		exit_failure("Error occurred in the close function", opts);
	normalize_map_buffer(opts);
	validate_map(opts);
	build_map_matrix(opts);
	log_parsed_info(opts);
	free_and_null(line_read);
}
