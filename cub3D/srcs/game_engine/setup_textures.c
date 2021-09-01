/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:53:26 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/09 21:52:29 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	setup_north_texture(t_game *opts)
{
	opts->tex.no.ptr = NULL;
	opts->tex.no.addr = NULL;
	opts->tex.no.width = 0;
	opts->tex.no.height = 0;
	opts->tex.no.ptr = mlx_xpm_file_to_image(opts->window.mlx,
			opts->tex.path.no, &opts->tex.no.width, &opts->tex.no.height);
	if (opts->tex.no.ptr == NULL)
		exit_failure("Fail to load north texture", opts);
	opts->tex.no.addr = mlx_get_data_addr(opts->tex.no.ptr,
			&opts->tex.no.bpp, &opts->tex.no.size_l, &opts->tex.no.endian);
	if (opts->tex.no.addr == NULL)
		exit_failure("Fail to load north texture", opts);
}

static void	setup_south_texture(t_game *opts)
{
	opts->tex.so.ptr = NULL;
	opts->tex.so.addr = NULL;
	opts->tex.so.ptr = mlx_xpm_file_to_image(opts->window.mlx,
			opts->tex.path.so, &opts->tex.so.width, &opts->tex.so.height);
	if (opts->tex.so.ptr == NULL)
		exit_failure("Fail to load south texture", opts);
	opts->tex.so.addr = mlx_get_data_addr(opts->tex.so.ptr,
			&opts->tex.so.bpp, &opts->tex.so.size_l, &opts->tex.so.endian);
	if (opts->tex.so.addr == NULL)
		exit_failure("Fail to load south texture", opts);
}

static void	setup_west_texture(t_game *opts)
{
	opts->tex.we.ptr = NULL;
	opts->tex.we.addr = NULL;
	opts->tex.we.ptr = mlx_xpm_file_to_image(opts->window.mlx,
			opts->tex.path.we, &opts->tex.we.width, &opts->tex.we.height);
	if (opts->tex.we.ptr == NULL)
		exit_failure("Fail to load west texture", opts);
	opts->tex.we.addr = mlx_get_data_addr(opts->tex.we.ptr,
			&opts->tex.we.bpp, &opts->tex.we.size_l, &opts->tex.we.endian);
	if (opts->tex.we.addr == NULL)
		exit_failure("Fail to load west texture", opts);
}

static void	setup_east_texture(t_game *opts)
{
	opts->tex.ea.ptr = NULL;
	opts->tex.ea.addr = NULL;
	opts->tex.ea.ptr = mlx_xpm_file_to_image(opts->window.mlx,
			opts->tex.path.ea, &opts->tex.ea.width, &opts->tex.ea.height);
	if (opts->tex.ea.ptr == NULL)
		exit_failure("Fail to load east texture", opts);
	opts->tex.ea.addr = mlx_get_data_addr(opts->tex.ea.ptr,
			&opts->tex.ea.bpp, &opts->tex.ea.size_l, &opts->tex.ea.endian);
	if (opts->tex.ea.addr == NULL)
		exit_failure("Fail to load east texture", opts);
}

void	setup_textures(t_game *opts, t_directions direction)
{
	if (direction == NORTH)
		setup_north_texture(opts);
	else if (direction == SOUTH)
		setup_south_texture(opts);
	else if (direction == WEST)
		setup_west_texture(opts);
	else if (direction == EAST)
		setup_east_texture(opts);
}
