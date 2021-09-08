/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wall_interceptions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	handle_horz_wall_collision(t_game *opts,
t_raycasting *horz, t_rayface ray_facing)
{
	while (horz->next_touch_x >= 0 && horz->next_touch_x <= opts->window.width
		&& horz->next_touch_y >= 0 && horz->next_touch_y <= opts->window.height)
	{
		horz->x_to_check = horz->next_touch_x;
		horz->y_to_check = horz->next_touch_y;
		if (ray_facing.up)
			horz->y_to_check += -1;
		if (has_wall_at(opts, horz->x_to_check, horz->y_to_check))
		{
			horz->wall_hit_x = horz->next_touch_x;
			horz->wall_hit_y = horz->next_touch_y;
			horz->found_wall_hit = TRUE;
			break ;
		}
		else
		{
			horz->next_touch_x += horz->xstep;
			horz->next_touch_y += horz->ystep;
		}
	}
}

void	handle_horz_intercept(t_game *opts, t_raycasting *horz,
t_rayface ray_facing, double ray_angle)
{
	horz->found_wall_hit = FALSE;
	horz->wall_hit_x = 0;
	horz->wall_hit_y = 0;
	horz->yintercept = floor(opts->player.y / TILE_SIZE) * TILE_SIZE;
	if (ray_facing.down)
		horz->yintercept += TILE_SIZE;
	horz->xintercept = opts->player.x
		+ (horz->yintercept - opts->player.y) / tan(ray_angle);
	horz->ystep = TILE_SIZE;
	if (ray_facing.up)
		horz->ystep *= -1;
	horz->xstep = TILE_SIZE / tan(ray_angle);
	if (ray_facing.left && horz->xstep > 0)
		horz->xstep *= -1;
	if (ray_facing.right && horz->xstep < 0)
		horz->xstep *= -1;
	horz->next_touch_x = horz->xintercept;
	horz->next_touch_y = horz->yintercept;
	handle_horz_wall_collision(opts, horz, ray_facing);
}

static void	handle_vert_wall_collision(t_game *opts,
t_raycasting *vert, t_rayface ray_facing)
{
	while (vert->next_touch_x >= 0 && vert->next_touch_x <= opts->window.width
		&& vert->next_touch_y >= 0 && vert->next_touch_y <= opts->window.height)
	{
		vert->x_to_check = vert->next_touch_x;
		if (ray_facing.left)
			vert->x_to_check += -1;
		vert->y_to_check = vert->next_touch_y;
		if (has_wall_at(opts, vert->x_to_check, vert->y_to_check))
		{
			vert->wall_hit_x = vert->next_touch_x;
			vert->wall_hit_y = vert->next_touch_y;
			vert->found_wall_hit = TRUE;
			break ;
		}
		else
		{
			vert->next_touch_x += vert->xstep;
			vert->next_touch_y += vert->ystep;
		}
	}
}

void	handle_vert_intercept(t_game *opts, t_raycasting *vert,
t_rayface ray_facing, double ray_angle)
{
	vert->found_wall_hit = FALSE;
	vert->wall_hit_x = 0;
	vert->wall_hit_y = 0;
	vert->xintercept = floor(opts->player.x / TILE_SIZE) * TILE_SIZE;
	if (ray_facing.right)
		vert->xintercept += TILE_SIZE;
	vert->yintercept = opts->player.y
		+ (vert->xintercept - opts->player.x) * tan(ray_angle);
	vert->xstep = TILE_SIZE;
	if (ray_facing.left)
		vert->xstep *= -1;
	vert->ystep = TILE_SIZE * tan(ray_angle);
	if (ray_facing.up && vert->ystep > 0)
		vert->ystep *= -1;
	if (ray_facing.down && vert->ystep < 0)
		vert->ystep *= -1;
	vert->next_touch_x = vert->xintercept;
	vert->next_touch_y = vert->yintercept;
	handle_vert_wall_collision(opts, vert, ray_facing);
}
