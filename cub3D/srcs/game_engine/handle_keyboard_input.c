/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:59:56 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/30 09:44:55 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	handle_keypress_event(int keycode, t_game *opts)
{
	if (keycode == ESC_KEY)
		close_window(opts);
	if (keycode == W_KEY)
		opts->player.walk_direction = opts->player.walk_direction + 1;
	else if (keycode == S_KEY)
		opts->player.walk_direction -= 1;
	else if (keycode == D_KEY)
		opts->player.strafe_direction += 1;
	else if (keycode == A_KEY)
		opts->player.strafe_direction -= 1;
	else if (keycode == RIGHT_ARROW_KEY)
		opts->player.turn_direction += 1;
	else if (keycode == LEFT_ARROW_KEY)
		opts->player.turn_direction -= 1;
	else if (keycode == M_KEY)
		opts->show_minimap = !opts->show_minimap;
	return (EXIT_SUCCESS);
}

int	handle_keyrelease_event(int keycode, t_game *opts)
{
	if (keycode == ESC_KEY)
		close_window(opts);
	if (keycode == W_KEY)
		opts->player.walk_direction = 0;
	else if (keycode == S_KEY)
		opts->player.walk_direction = 0;
	else if (keycode == D_KEY)
		opts->player.strafe_direction = 0;
	else if (keycode == A_KEY)
		opts->player.strafe_direction = 0;
	else if (keycode == RIGHT_ARROW_KEY)
		opts->player.turn_direction = 0;
	else if (keycode == LEFT_ARROW_KEY)
		opts->player.turn_direction = 0;
	return (EXIT_SUCCESS);
}
