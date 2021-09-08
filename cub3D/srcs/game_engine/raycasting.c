/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	set_hit_info(t_game *opts, t_raycasting horz,
t_raycasting vert, int column)
{
	if (vert.hit_distance < horz.hit_distance)
	{
		opts->rays[column].distance = vert.hit_distance;
		opts->rays[column].wall_hit_x = vert.wall_hit_x;
		opts->rays[column].wall_hit_y = vert.wall_hit_y;
		opts->rays[column].was_hit_vertical = TRUE;
	}
	else
	{
		opts->rays[column].distance = horz.hit_distance;
		opts->rays[column].wall_hit_x = horz.wall_hit_x;
		opts->rays[column].wall_hit_y = horz.wall_hit_y;
		opts->rays[column].was_hit_vertical = FALSE;
	}
	opts->rays[column].was_hit_horizontal
		= !opts->rays[column].was_hit_vertical;
}

static void	get_wall_hit_distance(t_game *opts, t_raycasting *horz,
t_raycasting *vert)
{
	if (horz->found_wall_hit)
	{
		horz->hit_distance = distance_between_points(opts->player.x,
				opts->player.y, horz->wall_hit_x, horz->wall_hit_y);
	}
	else
		horz->hit_distance = FLT_MAX;
	if (vert->found_wall_hit)
	{
		vert->hit_distance = distance_between_points(opts->player.x,
				opts->player.y, vert->wall_hit_x, vert->wall_hit_y);
	}
	else
		vert->hit_distance = FLT_MAX;
}

static void	get_ray_face_info(t_rayface *ray_facing, double ray_angle)
{
	ray_facing->down = ray_angle > 0 && ray_angle < PI;
	ray_facing->up = !ray_facing->down;
	ray_facing->right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	ray_facing->left = !ray_facing->right;
}

static void	cast_ray(t_game *opts, double ray_angle, int column)
{
	t_rayface		ray_facing;
	t_raycasting	horz;
	t_raycasting	vert;

	ray_angle = normalize_angle(ray_angle);
	get_ray_face_info(&ray_facing, ray_angle);
	handle_horz_intercept(opts, &horz, ray_facing, ray_angle);
	handle_vert_intercept(opts, &vert, ray_facing, ray_angle);
	get_wall_hit_distance(opts, &horz, &vert);
	set_hit_info(opts, horz, vert, column);
	opts->rays[column].ray_angle = ray_angle;
	opts->rays[column].face.down = ray_facing.down;
	opts->rays[column].face.up = ray_facing.up;
	opts->rays[column].face.left = ray_facing.left;
	opts->rays[column].face.right = ray_facing.right;
}

void	cast_all_rays(t_game *opts)
{
	double	ray_angle;
	int		column;

	column = -1;
	while (++column < opts->utils.num_rays)
	{
		ray_angle = opts->player.rotation_angle
			+ atan((column - opts->utils.num_rays / 2)
				/ opts->utils.dist_to_proj_plane);
		cast_ray(opts, ray_angle, column);
	}
}
