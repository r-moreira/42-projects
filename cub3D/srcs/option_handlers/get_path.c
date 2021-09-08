/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	exit_if_duplicated_path(t_game *opts, char *identifier, size_t len)
{
	if (len == SPRITE_ID_LEN)
	{
		if (!ft_strncmp("S", identifier, len) && opts->tex.path.s)
			exit_failure("The sprite path is duplicated", opts);
	}
	else
	{
		if (!ft_strncmp("NO", identifier, len) && opts->tex.path.no)
			exit_failure("The north texture path is duplicated", opts);
		else if (!ft_strncmp("SO", identifier, len) && opts->tex.path.so)
			exit_failure("The south texture path is duplicated", opts);
		else if (!ft_strncmp("WE", identifier, len) && opts->tex.path.we)
			exit_failure("The west texture path is duplicated", opts);
		else if (!ft_strncmp("EA", identifier, len) && opts->tex.path.ea)
			exit_failure("The east texture path is duplicated", opts);
	}
}

void	get_path(t_game *opts, char *line, char *identifier)
{
	size_t		id_len;
	size_t		path_len;
	size_t		path_start;
	char		*path;

	id_len = ft_strlen(identifier);
	exit_if_duplicated_path(opts, identifier, id_len);
	path_start = id_len;
	while (ft_isspace(line[path_start]))
		path_start++;
	path_len = path_start;
	while (line[path_len] != '\0' && !ft_isspace(line[path_len]))
		path_len++;
	path = ft_substr(line, (unsigned int)path_start, path_len - path_start);
	if (!ft_strncmp("NO", identifier, id_len) && id_len == TEXTURE_ID_LEN)
		opts->tex.path.no = path;
	else if (!ft_strncmp("SO", identifier, id_len) && id_len == TEXTURE_ID_LEN)
		opts->tex.path.so = path;
	else if (!ft_strncmp("WE", identifier, id_len) && id_len == TEXTURE_ID_LEN)
		opts->tex.path.we = path;
	else if (!ft_strncmp("EA", identifier, id_len) && id_len == TEXTURE_ID_LEN)
		opts->tex.path.ea = path;
	else if (!ft_strncmp("S", identifier, id_len) && id_len == SPRITE_ID_LEN)
		opts->tex.path.s = path;
}
