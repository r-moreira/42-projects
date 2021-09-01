/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wall_texture_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:37:50 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/11 11:53:27 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_teximg	define_which_wall_texture(t_game *opts, int index)
{
	if (opts->rays[index].face.up && !opts->rays[index].was_hit_vertical)
		return (opts->tex.no);
	else if (opts->rays[index].face.down && !opts->rays[index].was_hit_vertical)
		return (opts->tex.so);
	else if (opts->rays[index].face.right && opts->rays[index].was_hit_vertical)
		return (opts->tex.ea);
	else if (opts->rays[index].face.left && opts->rays[index].was_hit_vertical)
		return (opts->tex.we);
	return (opts->tex.no);
}

int	handle_wall_texture_color(t_game *opts, int index, int offset_x,
int offset_y)
{
	t_teximg	tex;
	t_color		wall_pixel;

	tex = define_which_wall_texture(opts, index);
	wall_pixel = get_texture_color(tex, offset_x, offset_y);
	if (opts->rays[index].was_hit_vertical)
		change_color_intensity(&wall_pixel, WALL_SHADOW_INTENSITY);
	return (wall_pixel);
}
