/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceil_and_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:34:15 by romoreir          #+#    #+#             */
/*   Updated: 2021/08/02 15:23:16 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	render_ceil_and_floor(t_game *opts, t_color ceil, t_color floor)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= opts->window.height)
	{
		while (x <= opts->window.width)
		{
			if (y <= opts->window.height / 2)
				draw_pixel(opts, x, y, ceil);
			else
				draw_pixel(opts, x, y, floor);
			x++;
		}
		y++;
		x = 0;
	}
}
