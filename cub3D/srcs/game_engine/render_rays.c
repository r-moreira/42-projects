/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	render_rays(t_game *opts)
{
	int	i;

	i = -1;
	while (++i < opts->utils.num_rays)
	{
		opts->line.x0 = opts->player.x * MINIMAP_SCALE;
		opts->line.y0 = opts->player.y * MINIMAP_SCALE;
		opts->line.x1 = opts->rays[i].wall_hit_x * MINIMAP_SCALE;
		opts->line.y1 = opts->rays[i].wall_hit_y * MINIMAP_SCALE;
		opts->line.color = color_picker(255, 0, 0);
		draw_line(opts);
	}
}
