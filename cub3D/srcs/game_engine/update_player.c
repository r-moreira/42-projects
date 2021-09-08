/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	handle_walk_step(t_game *opts)
{
	double	walk_step;
	double	new_x;
	double	new_y;

	walk_step = opts->player.walk_direction * opts->player.move_speed;
	new_x = opts->player.x + (cos(opts->player.rotation_angle) * walk_step);
	new_y = opts->player.y + (sin(opts->player.rotation_angle) * walk_step);
	if (!has_wall_at(opts, new_x, new_y))
	{
		opts->player.x = new_x;
		opts->player.y = new_y;
	}
}

static void	handle_strafe_step(t_game *opts)
{
	double	strafe_step;
	double	new_x;
	double	new_y;

	strafe_step = opts->player.strafe_direction * opts->player.move_speed;
	new_x = opts->player.x + (cos(opts->player.rotation_angle + PI / 2)
			* strafe_step);
	new_y = opts->player.y + (sin(opts->player.rotation_angle + PI / 2)
			* strafe_step);
	if (!has_wall_at(opts, new_x, new_y))
	{
		opts->player.x = new_x;
		opts->player.y = new_y;
	}
}

void	update_player(t_game *opts)
{
	opts->player.rotation_angle
		+= opts->player.turn_direction * opts->player.rotation_speed;
	opts->player.rotation_angle = normalize_angle(opts->player.rotation_angle);
	handle_walk_step(opts);
	handle_strafe_step(opts);
}
