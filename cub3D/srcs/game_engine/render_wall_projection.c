/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	get_wall_strip_heigth(t_game *opts, int index)
{
	double	theta;
	double	perpendicular_dist;
	double	wall_strip_height;

	theta = opts->rays[index].ray_angle - opts->player.rotation_angle;
	perpendicular_dist = opts->rays[index].distance * cos(theta);
	wall_strip_height = (TILE_SIZE / perpendicular_dist)
		* opts->utils.dist_to_proj_plane;
	opts->wall.strip_height = (int)wall_strip_height;
}

static void	get_wall_top_and_bottom_pixel(t_game *opts)
{
	int	top_pixel;
	int	bottom_pixel;

	top_pixel = (opts->window.height / 2) - (opts->wall.strip_height / 2);
	bottom_pixel = (opts->window.height / 2) + (opts->wall.strip_height / 2);
	if (top_pixel < 0)
		opts->wall.top_y = 0;
	else
		opts->wall.top_y = top_pixel;
	if (bottom_pixel > opts->window.height)
		opts->wall.bottom_y = opts->window.height;
	else
		opts->wall.bottom_y = bottom_pixel;
}

void	render_wall_projection(t_game *opts)
{
	int			x;
	int			y;

	x = -1;
	while (++x < opts->utils.num_rays)
	{
		if (opts->rays[x].was_hit_vertical)
			opts->wall.texture_offset_x
				= (int)opts->rays[x].wall_hit_y % TILE_SIZE;
		else
			opts->wall.texture_offset_x
				= (int)opts->rays[x].wall_hit_x % TILE_SIZE;
		get_wall_strip_heigth(opts, x);
		get_wall_top_and_bottom_pixel(opts);
		y = opts->wall.top_y;
		while (y++ < opts->wall.bottom_y)
		{
			opts->wall.distance_from_top = y + (opts->wall.strip_height / 2)
				- (opts->window.height / 2);
			opts->wall.texture_offset_y = opts->wall.distance_from_top
				* ((double)opts->tex.ea.height / opts->wall.strip_height);
			draw_pixel(opts, x, y, handle_wall_texture_color(opts, x,
					opts->wall.texture_offset_x, opts->wall.texture_offset_y));
		}
	}
}
