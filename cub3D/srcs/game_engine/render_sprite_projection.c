/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_projection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:49:11 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/11 11:55:10 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	get_visible_sprites(t_game *opts, t_sprite *visible_sprites,
t_sprite_utils *sprite_utils)
{
	float		angle_sprite_player;
	int			i;

	i = -1;
	while (++i < opts->map.item_count)
	{
		angle_sprite_player = opts->player.rotation_angle
			- atan2(opts->sprites[i].y - opts->player.y,
				opts->sprites[i].x - opts->player.x);
		if (angle_sprite_player > PI)
			angle_sprite_player -= TWO_PI;
		if (angle_sprite_player < -PI)
			angle_sprite_player += TWO_PI;
		angle_sprite_player = fabs(angle_sprite_player);
		if (angle_sprite_player < get_fov_angle() / 2 + SPRITE_VIEW_MARGIN)
		{
			opts->sprites[i].angle = angle_sprite_player;
			opts->sprites[i].distance = distance_between_points(
					opts->sprites[i].x, opts->sprites[i].y,
					opts->player.x, opts->player.y);
			visible_sprites[sprite_utils->count] = opts->sprites[i];
			sprite_utils->count++;
		}
	}
}

static void	sort_visible_sprites_by_distance(t_sprite *visible_sprites,
t_sprite_utils sprite_utils)
{
	t_sprite	temp;
	int			i;
	int			j;

	i = -1;
	while (++i < sprite_utils.count - 1)
	{
		j = i;
		while (++j < sprite_utils.count)
		{
			if (visible_sprites[i].distance < visible_sprites[j].distance)
			{
				temp = visible_sprites[i];
				visible_sprites[i] = visible_sprites[j];
				visible_sprites[j] = temp;
			}
		}
	}
}

static void	get_visible_sprite_info(t_game *opts, t_sprite sprite,
t_sprite_utils *sprite_utils)
{
	sprite_utils->perpendicular_dist = sprite.distance * cos(sprite.angle);
	sprite_utils->height = (TILE_SIZE / sprite_utils->perpendicular_dist)
		* opts->utils.dist_to_proj_plane;
	sprite_utils->width = sprite_utils->height;
	sprite_utils->top_y = (opts->window.height / 2)
		- (sprite_utils->height / 2);
	if (sprite_utils->top_y < 0)
		sprite_utils->top_y = 0;
	sprite_utils->bottom_y = (opts->window.height / 2)
		+ (sprite_utils->height / 2);
	if (sprite_utils->bottom_y > opts->window.height)
		sprite_utils->bottom_y = opts->window.height;
	sprite_utils->angle = atan2(sprite.y - opts->player.y,
			sprite.x - opts->player.x) - opts->player.rotation_angle;
	sprite_utils->screen_pos_x = tan(sprite_utils->angle)
		* opts->utils.dist_to_proj_plane;
	sprite_utils->left_x = (opts->window.width / 2) + sprite_utils->screen_pos_x
		- (sprite_utils->width / 2);
	sprite_utils->right_x = sprite_utils->left_x + sprite_utils->width;
}

static void	render_visible_sprite(t_game *opts, t_sprite s, t_sprite_utils *ut)
{
	t_color	texel_color;
	int		x;
	int		y;

	x = ut->left_x;
	while (x++ < ut->right_x)
	{
		ut->offset_x = (x - ut->left_x) * (opts->tex.s.width / ut->width);
		y = ut->top_y;
		while (y++ < ut->bottom_y)
		{
			if (x > 0 && x < opts->window.width && y > 0
				&& y < opts->window.width)
			{
				ut->dist = y + (ut->height / 2) - (opts->window.height / 2);
				ut->offset_y = ut->dist * (opts->tex.s.height / ut->height);
				texel_color = get_texture_color(opts->tex.s, ut->offset_x,
						ut->offset_y);
				if (s.distance < opts->rays[x].distance
					&& texel_color != color_picker(0, 0, 0))
					draw_pixel(opts, x, y, texel_color);
			}
		}
	}
}

void	render_sprite_projection(t_game *opts)
{
	t_sprite		*visible_sprites;
	t_sprite_utils	sprite_utils;
	int				i;

	visible_sprites = (t_sprite *)malloc(sizeof(t_sprite)
			* opts->map.item_count + 1);
	sprite_utils.count = 0;
	get_visible_sprites(opts, visible_sprites, &sprite_utils);
	sort_visible_sprites_by_distance(visible_sprites, sprite_utils);
	i = -1;
	while (++i < sprite_utils.count)
	{
		get_visible_sprite_info(opts, visible_sprites[i], &sprite_utils);
		render_visible_sprite(opts, visible_sprites[i], &sprite_utils);
	}
	free(visible_sprites);
}
