/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:13:44 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/27 16:11:47 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	get_floor_rgb(t_game *opts, char *line)
{
	char	**rgb;
	int		i;

	if (opts->floor.r != UNDEFINED || opts->floor.g != UNDEFINED
		|| opts->floor.b != UNDEFINED)
		exit_failure("There is a duplicated floor RGB option", opts);
	line++;
	while (ft_isspace(*line))
		line++;
	rgb = ft_split(line, ',');
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		exit_failure("The floor RGB format is incorrect", opts);
	opts->floor.r = ft_atoi(rgb[0]);
	opts->floor.g = ft_atoi(rgb[1]);
	opts->floor.b = ft_atoi(rgb[2]);
	if (opts->floor.r < 0 || opts->floor.g < 0 || opts->floor.b < 0
		|| opts->floor.r > 255 || opts->floor.g > 255 || opts->floor.b > 255)
		exit_failure("The floor RGB format is incorrect", opts);
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free_and_null(rgb);
}

static void	get_ceil_rgb(t_game *opts, char *line)
{
	char	**rgb;
	int		i;

	if (opts->ceil.r != UNDEFINED || opts->ceil.g != UNDEFINED
		|| opts->ceil.b != UNDEFINED)
		exit_failure("There is a duplicated ceil RGB option", opts);
	line++;
	while (ft_isspace(*line))
		line++;
	rgb = ft_split(line, ',');
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		exit_failure("The ceil RGB format is incorrect", opts);
	opts->ceil.r = ft_atoi(rgb[0]);
	opts->ceil.g = ft_atoi(rgb[1]);
	opts->ceil.b = ft_atoi(rgb[2]);
	if (opts->ceil.r < 0 || opts->ceil.g < 0 || opts->ceil.b < 0
		|| opts->ceil.r > 255 || opts->ceil.g > 255 || opts->ceil.b > 255)
		exit_failure("The ceil RGB format is incorrect", opts);
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free_and_null(rgb);
}

void	get_rgb(t_game *opts, char *line)
{
	if (*line == 'F')
		get_floor_rgb(opts, line);
	if (*line == 'C')
		get_ceil_rgb(opts, line);
}
