/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:30:18 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/11 11:51:00 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	game_loop(t_game *opts)
{
	render_ceil_and_floor(opts,
		color_picker(opts->ceil.r, opts->ceil.g, opts->ceil.b),
		color_picker(opts->floor.r, opts->floor.g, opts->floor.b));
	update_player(opts);
	cast_all_rays(opts);
	render_wall_projection(opts);
	render_sprite_projection(opts);
	if (opts->show_minimap)
		render_minimap(opts);
	mlx_put_image_to_window(opts->window.mlx, opts->window.ptr,
		opts->image.ptr, 0, 0);
	return (EXIT_SUCCESS);
}
